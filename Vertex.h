#ifndef Vertex_h
#define Vertex_h
#include "naglowki.h"

class Vertex
{
	int id;
	int X;
	int Y;
	bool visited;
	double shortestWay;
	int previousVertex;


	// AStar
	double distance;
	double aStarDistance;



public:
	Vertex();
	int getId();
	void setId(int id);
	int getX();
	void setX(int X);
	int getY();
	void setY(int Y);
	bool getVisit();
	void setVisit(bool visit);
	int getWay();
	void setWay(int way);
	int getPrev();
	void setPrev(int prev);
	double getDistance();
	void setDistance(double distance);
	double getAStarDistance();
	void setAStarDistance(double distance);
};
class VertexList
{
	double X;
	double Y;
	double kat;
	int length;

public:
	VertexList * next;

	VertexList();
	VertexList(double X, double Y, int length);
	int getLength();
	void setLength(int length);
	double getX();
	void setX(double X);
	double getY();
	void setY(double Y);
	double getKat();
	void setKat(double kat);


};

void add(VertexList *&Head, double graczX, double graczY,int licznik);
void wyswietl(VertexList *Head);
void wyrzuc(VertexList *&Head);
void objectMoving(VertexList * tab1, VertexList * tab2, int &predkoscX, int &predkoscY);
void objectMoving2(double& graczX, double& graczY, double myszX, double myszY, double &predkoscX, double &predkoscY);
void objectMoving3(VertexList * tab1, double &pozX, double &pozY);
//additional functions
void loadVertex(std::string mapName, Vertex *& vertexTab, int vertexCount, std::string tableName, int** valueTable);
void lineDrawing(Vertex * tab, int it, int jt, sf::Image &imagePodkladu, sf::Color kolor);
int closestVertex(Vertex * vertexTab, int vertexCount, int X, int Y);
void vertexMarker(sf::Image &imagePodkladu, Vertex* vertexTab, int vertexCount);
void vertexReset(Vertex *& vertexTab, int vertexCount);
#endif