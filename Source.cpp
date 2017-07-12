#include "naglowki.h"
#include "postacie.h"
#include "sterowanie.h"
#include "naboje.h"
#include "Dikstra.h"
#include "AStar.h"
#define WINDOW_HEIGHT 720
#define WINDOW_WIDTH 1280

using namespace std;



int main()
{

	float playerHeight = 20;
	float playerWidth = 20;
	float playerSpeed = 5;
	float kat = 0;
	float PI = 3.14;
	bool zmianaPozycji = true;
	bool strzal = true;
	int ostatni = 0;
	int obecny = 0;
	string mapName = "mapy/wektor_proba.txt";
	string tableName = "mapy/proba.txt";
	sf::String dikstraString = "Dikstra";
	sf::String aStarString = "A*";
	int vertexCount = 0;
	int iteracja = 0;
	double predkoscX = 0;
	double predkoscY = 0;
	double pozycjaX = 1;
	double pozycjaY = 0;
	bool stop = false;

	int ktoryAlgorytm = 0;  // 0-dikstra  1- AStar





	//==================    OBIEKTY          =========================================
	bohater A(45, 45);
	bohater B(1130, 580);
	Myszka myszkaStrzal;
	Myszka katMyszki;
	Prosta prosta;

	




	VertexList * Head = NULL;
	VertexList * wsk = Head;






	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Podleze Slayer 3");
	sf::Clock clock;
	sf::Time time;

	
	
	sf::Texture teksturaA;
	sf::Sprite spriteA;

	sf::Texture teksturaB;
	sf::Sprite spriteB;

	sf::Sprite mapa;
	sf::Texture teksturaMapy;

	sf::Texture podkladMapy;
	sf::Texture podstawienieMapy;
	


	sf::Texture pociskTekstura;
	sf::Sprite pociskSprite1;
	
	//=================================    USTAWIENIA   ==================================================================


	if (!teksturaMapy.loadFromFile("mapy/podklad2.png"))
	//if (!teksturaMapy.loadFromFile("mapy/punkty1.png"))
	{
		std::cout << "Error" << std::endl;
	}
	if (!podkladMapy.loadFromFile("mapy/podklad2.png"))
	{
		std::cout << "Error" << std::endl;
	}
	if (!teksturaA.loadFromFile("postac3.png"))
	{
		std::cout << "Error" << std::endl;
	}
	if (!teksturaB.loadFromFile("postac2.png"))
	{
		std::cout << "Error" << std::endl;
	}

	
	
	mapa.setTexture(teksturaMapy);

	spriteA.setTexture(teksturaA);
	spriteA.setPosition(A.getX(), A.getY());
	spriteA.setOrigin(playerWidth/2, playerHeight / 2);

	spriteB.setTexture(teksturaB);
	spriteB.setPosition(B.getX(), B.getY());
	spriteB.setOrigin(playerWidth / 2, playerHeight / 2);


	podstawienieMapy = teksturaMapy;

	sf::Image imagePodkladu = teksturaMapy.copyToImage();

	window.setFramerateLimit(60);


	int index = 0;
	Mapa mapaPodklad(teksturaMapy);

	std::fstream plik1(mapName, std::ios::in | std::ios::out);
	plik1 >> vertexCount;
	plik1.close();

	Vertex * vertexTab = new Vertex[vertexCount];
	int ** valueTable = new int*[vertexCount];
	for (int i = 0; i < vertexCount; i++)
	{

		valueTable[i] = new int[vertexCount];
	}
	
	loadVertex(mapName, vertexTab, vertexCount,tableName, valueTable);
	vertexMarker(imagePodkladu, vertexTab, vertexCount);
	teksturaMapy.loadFromImage(imagePodkladu);
	podkladMapy = teksturaMapy;
	imagePodkladu = podkladMapy.copyToImage();
	mapa.setTexture(teksturaMapy);


	pozycjaX = vertexTab[0].getX();
	pozycjaY = vertexTab[0].getY();
	spriteA.setPosition(pozycjaX,pozycjaY);

	
	
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		cout << "nie poszlo" << endl;
	}
	
	
	sf::Text algorytm(dikstraString, font, 40);
	algorytm.setFillColor(sf::Color::Magenta);
	algorytm.setPosition(((WINDOW_WIDTH/2) - algorytm.getCharacterSize()/2*(dikstraString.getSize()/2)), WINDOW_HEIGHT/2 - 25);

	// ======================================== G£ÓWNY WHILE  ==================================




	while (window.isOpen())

	{
		
			

		

			//===========================    MYSZKA   =============================================================
			sf::Event event;
			window.pollEvent(event);
			
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::MouseButtonPressed:

					
					if (event.mouseButton.button == sf::Mouse::Left && strzal)
					{
						
						wyrzuc(Head);
						
						
						obecny = closestVertex(vertexTab, vertexCount, sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
						if (obecny == 9999)
						{
							cout << " nie trafiles" << endl;
						}
						else
						{
							if (ktoryAlgorytm == 0) // Dikstra
							{

								Head = dikstraPathFinding(ostatni, obecny, vertexTab, valueTable, vertexCount, imagePodkladu);
							}
							else if (ktoryAlgorytm == 1) // A*
							{

								Head = aStarPathFinding(ostatni, obecny, vertexTab, valueTable, vertexCount, imagePodkladu);
							}
							else
							{
								cout << "jakis 3 algorytm albo zle wybrales nr";
							}
							// 



							wsk = Head;
							//wyswietl(wsk);
							ostatni = obecny;
							teksturaMapy.loadFromImage(imagePodkladu);
							imagePodkladu = podkladMapy.copyToImage();
							mapa.setTexture(teksturaMapy);
							
						}

						

						strzal = false;
					}
					break;
				case sf::Event::MouseButtonReleased:


					strzal = true;
					break;
				case sf::Event::KeyPressed:
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
					{
						if (ktoryAlgorytm == 0)
						{
							ktoryAlgorytm = 1;
							algorytm.setString("A*");
							algorytm.setFillColor(sf::Color::Green);
							algorytm.setPosition(((WINDOW_WIDTH / 2) - 20 * (aStarString.getSize() / 2)), WINDOW_HEIGHT / 2 - 25);
						}
						else if (ktoryAlgorytm == 1)
						{
							ktoryAlgorytm = 0;
							algorytm.setString("Dikstra");
							algorytm.setFillColor(sf::Color::Magenta);
							algorytm.setPosition(((WINDOW_WIDTH / 2) - 20 * (dikstraString.getSize() / 2)), WINDOW_HEIGHT / 2 - 25);
						}
					}
					break;
			}
			
			// ======================================           PORUSANIE OBIEKTU        ==========================================================
			
			pozycjaX = spriteA.getPosition().x;
			pozycjaY = spriteA.getPosition().y;

			if (wsk != NULL)
			{
				
				if (((pozycjaX == wsk->getX()) && (pozycjaY == wsk->getY())))
				//if ((pozycjaX < wsk->getX() + 3 && pozycjaX > wsk->getX() - 3) && (pozycjaY < wsk->getY() + 3 && pozycjaY > wsk->getY() - 3))
				{
					
					wsk = wsk->next;
				}
				else
				{
					objectMoving3(wsk, pozycjaX, pozycjaY);
					spriteA.setPosition(pozycjaX, pozycjaY);
					spriteA.setRotation(wsk->getKat() * 180 / PI);
				}
			}
			




			//=======================================               DEBUG                    ===================================================================

	
			//wyswietl(Head);
		//===================================        WYSWIETLANIE      ======================================================

		window.clear();
		time = clock.restart();


		window.draw(mapa);
	
		

		
		//window.draw(spriteB);
		window.draw(spriteA);
		window.draw(algorytm);
		window.display();
	}
	//======================
	delete vertexTab;
	return 0;
}