#ifndef postacie_h
#define postacie_h
#include "naglowki.h"


//====================================================  BOHATER  ==========================================================


class bohater
{
	double x, y;
	double zycie;
public:
	bohater();
	bohater(double x, double y);
	double getX();
	double getY();
	void setX(double x);
	void setY(double y);
};






//====================================================  POTWOR  ==========================================================

class potwor
{
	double x, y;
	double zycie;
	potwor();

};

#endif