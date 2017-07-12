#include "naglowki.h"
#include "postacie.h"


//====================================================  BOHATER  ==========================================================
bohater::bohater()
{

}
bohater::bohater(double x, double y)
{
	this->x = x;
	this->y = y;
	this->zycie = 100;
}
double bohater::getX()
{
	return this->x;
}
double bohater::getY()
{
	return this->y;
}
void bohater::setX(double x)
{
	this->x = x;
}
void bohater::setY(double y)
{
	this->y = y;
}

//====================================================  POTWOR  ==========================================================

potwor::potwor()
{
	int los = 0;
	los = rand() % 4;
	if (los == 0)
	{
		this->x = 1;
		this->y = rand() % 598 + 1;
	}
	else if (los == 1)
	{
		this->x = 799;
		this->y = rand() % 598 + 1;
	}
	else if (los == 2)
	{
		this->x = rand() % 798 + 1;
		this->y = 1;
	}
	else if (los == 3)
	{
		this->x = rand() % 798 + 1;
		this->y = 598;
	}
}