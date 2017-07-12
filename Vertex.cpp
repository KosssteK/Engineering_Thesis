#include "Vertex.h"
//====================================== Vertex 
Vertex::Vertex()
{
	this->id = 0;
	this->X = 0;
	this->Y = 0;
	this->visited = false;
	this->shortestWay = 99999999;
	this->previousVertex = this->id;
	this->distance = 99999999;
	this->aStarDistance = 99999999;





}
int Vertex::getId()
{
	return this->id;
}
void Vertex::setId(int id)
{
	this->id = id;
}
int Vertex::getX()
{
	return this->X;
}
void Vertex::setX(int X)
{
	this->X = X;
}
int Vertex::getY()
{
	return this->Y;
}
void Vertex::setY(int Y)
{
	this->Y = Y;
}
bool Vertex::getVisit()
{
	return this->visited;
}
void Vertex::setVisit(bool visit)
{
	this->visited = visit;
}
int Vertex::getWay(){
	return this->shortestWay;
}
void Vertex::setWay(int way)
{
	this->shortestWay = way;
}
int Vertex::getPrev()
{
	return this->previousVertex;
}
void Vertex::setPrev(int prev)
{
	this->previousVertex = prev;
}
double Vertex::getDistance()
{
	return this->distance;
}
void Vertex::setDistance(double distance)
{
	this->distance = distance;
}
double Vertex::getAStarDistance()
{
	return this->aStarDistance;
}
void Vertex::setAStarDistance(double distance)
{
	this->aStarDistance = distance;
}
//==================================== VertexList
VertexList::VertexList()
{
	this->X = 0;
	this->Y = 0;
	this->length = 0;
}
VertexList::VertexList(double X, double Y, int length)
{
	this->X = X;
	this->Y = Y;
	this->length = length;
}
double VertexList::getX()
{
	return this->X;
}
void VertexList::setX(double X)
{
	this->X = X;
}
double VertexList::getY()
{
	return this->Y;
}
void VertexList::setY(double Y)
{
	this->Y = Y;
}
double VertexList::getKat()
{
	return this->kat;
}
void VertexList::setKat(double kat)
{
	this->kat = kat;
}
int VertexList::getLength()
{
	return this->length;
}
void VertexList::setLength(int length)
{
	this->length = length;
}
void add(VertexList *&Head, double graczX, double graczY, int licznik)
{
	VertexList * cegla = new VertexList(graczX, graczY, licznik);
	cegla->next = Head;
	Head = cegla;
}
void wyswietl(VertexList *Head){
	VertexList *p = Head;
	std::cout << "Head" << "->" << std::endl;
	if (Head != NULL)
	{

		while (p != NULL)
		{

			std::cout << "|" << p->getX() << "-" << p->getY() << "|=";
			p = p->next;

		}
	}
	std::cout << "NULL" << std::endl;
}
void wyrzuc(VertexList *&Head){
	VertexList * wsk = Head;
	if (Head != NULL)
	{
		Head = Head->next;
		delete wsk;

	}
	else
	{
		std::cout << "Lista pusta jak Macka glowa!" << std::endl;
	}

}
void objectMoving(VertexList * tab1, VertexList * tab2, int &predkoscX, int &predkoscY)
{


	double x = tab1->getX();
	double y = tab1->getY();

	double dlugoscOX = tab1->getX() - tab2->getX();
	double dlugoscOY = tab1->getY() - tab2->getY();
	double dlugoscX = abs(dlugoscOX);
	double dlugoscY = abs(dlugoscOY);
	double stosunekX = 0;
	double stosunekY = 0;



	if (dlugoscX<dlugoscY)
	{
		stosunekX = -dlugoscOX / dlugoscY;
		stosunekY = -dlugoscOY / dlugoscY;
	}
	else
	{
		stosunekX = -dlugoscOX / dlugoscX;
		stosunekY = -dlugoscOY / dlugoscX;
	}
	predkoscX = stosunekX;
	predkoscY = stosunekY;

}
void objectMoving2(double& graczX, double& graczY, double myszX, double myszY, double &predkoscX, double &predkoscY)
{


	double z = 1;
	double X = graczX - myszX;
	double Y = graczY - myszY;

	double a;
	double b;

	a = sqrt((z * X*X) / (Y*Y + X*X));
	b = Y*a / X;

	if (X > 0)
	{
		a = -a;
	}
	if (a < 0)
	{
		b = -b;
	}


	predkoscX = round(a);
	predkoscY = round(b);
	graczX += predkoscX;
	graczY += predkoscY;





}
void objectMoving3(VertexList * tab1, double &pozX, double &pozY)
{

	double predkosc = 4;
	double x = pozX;
	double y = pozY;

	double dlugoscOX = pozX - tab1->getX();
	double dlugoscOY = pozY - tab1->getY();
	double dlugoscX = abs(dlugoscOX);
	double dlugoscY = abs(dlugoscOY);
	double stosunekX = 0;
	double stosunekY = 0;



	if (dlugoscX<dlugoscY)
	{
		stosunekX = -dlugoscOX / dlugoscY;
		stosunekY = -dlugoscOY / dlugoscY;
	}
	else
	{
		stosunekX = -dlugoscOX / dlugoscX;
		stosunekY = -dlugoscOY / dlugoscX;
	}

	int odleglosc = sqrt((pozX - tab1->getX())*(pozX - tab1->getX()) + (pozY - tab1->getY())*(pozY - tab1->getY()));
	int odlegloscZPredkoscia = sqrt(((pozX + stosunekX*predkosc) - pozX)*((pozX + stosunekX*predkosc) - pozX) + ((pozY + stosunekY*predkosc) - pozY)*((pozY + stosunekY*predkosc) - pozY));



	if (odleglosc > odlegloscZPredkoscia)
	{
		pozX += stosunekX*predkosc;
		pozY += stosunekY*predkosc;
		tab1->setKat(atan2(tab1->getY() - pozY, tab1->getX() - pozX));
	}
	else
	{
		pozX = tab1->getX();
		pozY = tab1->getY();
		tab1->setKat(atan2(0, 0));
	}


}
//====================================== OTHER
void loadVertex(std::string mapName, Vertex*& vertexTab, int vertexCount, std::string tableName, int** valueTable)
{


	std::fstream plik1(mapName, std::ios::in | std::ios::out);
	int zmienna = 0;
	if (plik1.is_open())
	{
		plik1 >> zmienna;
		for (int i = vertexCount - 1; i >= 0; i--)
		{

			plik1 >> zmienna;
			vertexTab[i].setId(zmienna);
			//std::cout << vertexTab[i].getId() << std::endl;
			plik1 >> zmienna;
			vertexTab[i].setX(zmienna);
			plik1 >> zmienna;
			vertexTab[i].setY(zmienna);
		}
	}
	else
	{
		std::cout << "tez nie pyklo" << std::endl;
	}
	plik1.close();

	std::fstream plik2(tableName, std::ios::in | std::ios::out);
	if (plik2.is_open())
	{
		for (int i = 0; i < vertexCount; i++)
		{
			for (int j = 0; j < vertexCount; j++)
			{
				plik2 >> valueTable[i][j];
				//std::cout.width(4);
				//std::cout << valueTable[i][j] << " ";
			}
			//std::cout << std::endl;
		}
	}
	else
	{
		std::cout << "nie pyklo" << std::endl;
	}



	plik2.close();



}
void lineDrawing(Vertex * tab, int it, int jt, sf::Image &imagePodkladu, sf::Color kolor)
{
	int naIle = 1;
	int promienGracza = 5;

	double x = tab[it].getX();
	double y = tab[it].getY();

	double dlugoscOX = tab[it].getX() - tab[jt].getX();
	double dlugoscOY = tab[it].getY() - tab[jt].getY();
	double dlugoscX = abs(dlugoscOX);
	double dlugoscY = abs(dlugoscOY);
	double stosunekX = 0;
	double stosunekY = 0;



	if (dlugoscX<dlugoscY)
	{
		stosunekX = -dlugoscOX / dlugoscY;
		stosunekY = -dlugoscOY / dlugoscY;
	}
	else
	{
		stosunekX = -dlugoscOX / dlugoscX;
		stosunekY = -dlugoscOY / dlugoscX;
	}

	double startowyX = tab[it].getX();
	double startowyY = tab[it].getY();


	if (dlugoscX < dlugoscY)
	{
		for (int i = 0; i <= dlugoscX / naIle; i++)
		{
			for (int j = 0; j <= dlugoscY / naIle; j++)
			{
				//std::cout << "tu " << std::endl;
				imagePodkladu.setPixel(startowyX + round(stosunekX*j)*naIle, startowyY + round(stosunekY*j)*naIle, kolor);
				//std::cout << "tu " << std::endl;
			}
		}
	}
	else
	{
		for (int i = 0; i <= dlugoscX / naIle; i++)
		{
			for (int j = 0; j <= dlugoscY / naIle; j++)
			{
				//std::cout << " a tu juz nie" << std::endl;
				imagePodkladu.setPixel(startowyX + round(stosunekX*i)*naIle, startowyY + round(stosunekY*i)*naIle, kolor);
				//std::cout << " a tu juz nie" << std::endl;
			}
		}
	}






}
int closestVertex(Vertex * vertexTab, int vertexCount, int X, int Y)
{
	int index = 0;
	int ile = 10;
	for (int i = 0; i < vertexCount; i++)
	{
		if (X < vertexTab[i].getX() + ile && X > vertexTab[i].getX() - ile && Y < vertexTab[i].getY() + ile && Y > vertexTab[i].getY() - ile)
		{
			index = i;
			return index;
		}
	}

	return 9999;

}
void vertexMarker(sf::Image &imagePodkladu, Vertex* vertexTab, int vertexCount)
{
	for (int z = 0; z < vertexCount; z++)
	{
		for (int i = vertexTab[z].getX() - 5; i < vertexTab[z].getX() + 5; i++)
		{
			for (int j = vertexTab[z].getY() - 5; j < vertexTab[z].getY() + 5; j++)
			{
				imagePodkladu.setPixel(i, j, sf::Color::Red);
			}
		}
	}



}
void vertexReset(Vertex *& vertexTab, int vertexCount)
{
	for (int i = 0; i < vertexCount; i++)
	{
		vertexTab[i].setVisit(false);
		vertexTab[i].setWay(99999999);
		vertexTab[i].setPrev(0);
		vertexTab[i].setDistance(99999999);
		vertexTab[i].setAStarDistance(99999999);
	}
}