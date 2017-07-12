#ifndef Naboje_h
#define Naboje_h
#include "naglowki.h"
class Punkt
{
public:
	double x;
	double y;
	Punkt();
	Punkt(double x, double y);
};

class Naboj
	:public Punkt
{
public:
	double a;
	double b;
	float kat;
	double predkoscX;
	double predkoscY;
	int cw;
	sf::Sprite pociskSprite;
	Naboj *next;
	/*Naboj();
	Naboj(double x, double y, double a, double b, float kat);
	//stare
	static double poruszaj(Naboj * Head, double &x, double &y, double stos1, double stos2, int cw, float kat);
	static void dorzuc(Naboj *&Head, double x, double y, double a, double b, float kat);
	static void wyswietl(Naboj *Head);
	static bool wyrzuc(Naboj *&Head, Naboj *&wsk);
	*/
	//nowe
	Naboj();
	Naboj(double graczX, double graczY, double myszX, double myszY, sf::Sprite teksturaPocisku);
	static void dorzuc(Naboj *&Head, double graczX, double graczY, double myszX, double myszY, sf::Sprite teksturaPocisku);
	static void przemiesc(Naboj *&Head);
	static void wyswietl(Naboj *Head);
	bool ograniczeniePocisk(sf::Image podkladMapy);
	static void wyrzuc(Naboj*&Head, Naboj *&poprzednieP, Naboj *&aktualneP);
	static void kolizjaNaboju(Naboj *&Head, sf::Image podkladMapy);
};
class Prosta
{
public:
	double a;
	double b;
	Prosta();
	Prosta(double a, double b);

};

Prosta rownanie(double x, double y, double a, double b);
Punkt wspPkt(Prosta A);
void stosunek(Naboj *Head, double &x, double &y, double a, double b, int cw);


#endif