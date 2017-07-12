#include "Dikstra.h"

VertexList * dikstraPathFinding(int startId, int endId, Vertex *& vertexTab, int ** valueTable, int vertexCount, sf::Image &imagePodkladu)
{
	VertexList * wsk = NULL;
	vertexReset(vertexTab, vertexCount);

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
					odleglosc = vertexTab[current].getWay() + valueTable[current][i];
					if (odleglosc < vertexTab[i].getWay())
					{
						vertexTab[i].setWay(odleglosc);
						vertexTab[i].setPrev(current + 1);
						lineDrawing(vertexTab, current, i, imagePodkladu, sf::Color::Magenta);
					}
				}
			}


			int shortestPath = 9999999;
			int index = 0;
			for (int i = 0; i < vertexCount; i++)
			{
				if (shortestPath > vertexTab[i].getWay() && vertexTab[i].getVisit() == false)
				{
					shortestPath = vertexTab[i].getWay();
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
		lineDrawing(vertexTab, indexPoczatkowy, vertexTab[indexPoczatkowy].getPrev()-1, imagePodkladu, sf::Color::Black);
		

		indexPoczatkowy = vertexTab[indexPoczatkowy].getPrev()-1;
		licznik++;

	}
	add(wsk, vertexTab[indexPoczatkowy].getX(), vertexTab[indexPoczatkowy].getY(), licznik);
	
	return wsk;
}
