#include "AStar.h"


VertexList * aStarPathFinding(int startId, int endId, Vertex *& vertexTab, int ** valueTable, int vertexCount, sf::Image &imagePodkladu)
{
	VertexList *wsk = NULL;
	vertexReset(vertexTab, vertexCount);
	
	for (int i = 0; i < vertexCount; i++)
	{
		vertexTab[i].setDistance(sqrt((vertexTab[i].getX() - vertexTab[endId].getX())*(vertexTab[i].getX() - vertexTab[endId].getX()) + (vertexTab[i].getY() - vertexTab[endId].getY())*(vertexTab[i].getY() - vertexTab[endId].getY())));
	}


	int current = startId;
	int odleglosc = 0;
	vertexTab[current].setVisit(true);
	vertexTab[current].setWay(0);
	

	for (int z = 0; z < vertexCount; z++)  // do momentu dojscia do B
	{
		if (current != endId)
		{

			for (int i = 0; i < vertexCount; i++)   // sprawdzenie wszystkich polaczen z obecnym wezlem
			{
				if (valueTable[current][i] != 0 && vertexTab[i].getVisit() == false) //sprawdzenie polaczen w sasiedztwie
				{
					odleglosc = vertexTab[current].getWay() + valueTable[current][i] + vertexTab[i].getDistance();
					if (odleglosc < vertexTab[i].getAStarDistance())
					{
						vertexTab[i].setWay(odleglosc - vertexTab[i].getDistance());
						vertexTab[i].setPrev(current + 1);
						vertexTab[i].setAStarDistance(odleglosc);
						lineDrawing(vertexTab, current, i, imagePodkladu, sf::Color::Green);
						//std::cout << "current: " << current << " i " << i << std::endl;
					}
				}
			}

			

			int shortestPath = 9999999;
			int index = 0;
			for (int i = 0; i < vertexCount; i++)
			{
				if (shortestPath > vertexTab[i].getAStarDistance() && vertexTab[i].getVisit() == false)
				{
					shortestPath = vertexTab[i].getAStarDistance();
					index = i;
				}
			}
			current = index;
			vertexTab[current].setVisit(true);
		}
		else
		{
			break;
		}
	}



	int indexPoczatkowy = endId;
	int licznik = 1;



	while (indexPoczatkowy != startId)
	{
		
		add(wsk, vertexTab[indexPoczatkowy].getX(), vertexTab[indexPoczatkowy].getY(), licznik);

		lineDrawing(vertexTab, indexPoczatkowy, vertexTab[indexPoczatkowy].getPrev() - 1, imagePodkladu, sf::Color::Black);


		indexPoczatkowy = vertexTab[indexPoczatkowy].getPrev() - 1;
		licznik++;

	}
	add(wsk, vertexTab[indexPoczatkowy].getX(), vertexTab[indexPoczatkowy].getY(), licznik);
	
	return wsk;
}

//