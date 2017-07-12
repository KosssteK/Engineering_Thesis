#include "Naboje.h"
#include "naglowki.h"



///======================      PROSTA=
Prosta::Prosta()
{
	a = 1;
	b = 1;
}

Prosta::Prosta(double a, double b)
{
	this->a = a;
	this->b = b;
}
Prosta rownanie(double x, double y, double a, double b)
{

	//y = a*x + b;	(3,1)	1=3a+b	b=1-3a				b=-2
	//y = a*x + b;	(5,3)	3=5a+b	3=5a+1-3a	2=2a	a=1
	//	y1-y2=ax1-ax2	y1-y2=a(x1-x2)	a=(y1-y2)/(x1-x2)
	//b = y1 - ax1;

	Prosta Wynik;
	if ((x - a) != 0)
	{
		Wynik.a = (y - b) / (x - a);
		//	Wynik.b = y - (Wynik.a * x);
		Wynik.b = 0;
	}
	else
	{
		Wynik.a = 0;
		Wynik.b = 0;
	}
	return Wynik;
}
Punkt wspPkt(Prosta A)
{
	// a b x1 y1 x2 y2

	double a1, b1, c1;
	double r = 10;
	double delta;
	double x1, x2;
	double y1, y2;
	int X, Y;
	//x ^ 2 + y ^ 2 = r ^ 2												x ^ 2 + y ^ 2 = r^2		x^2 + (ax+b)^2 =r^2		xx + aaxx +2abx +bb = rr		1-aa(xx) +2abx +bb-rr =0	d=16 + 4*21*2	184
	//y = a*x + b																									y=x-2
	//Prosta X(1,0);
	//wspPkt(X, 1);

	//std::cout << A.a << "   1   " << A.b << std::endl;

	a1 = 1 + (A.a*A.a);
	//a1 = 1 + A.a;
	b1 = 2 * A.a * A.b;
	c1 = (A.b*A.b) - r*r;

	delta = (b1*b1) - (4 * a1*c1);

	x1 = (-1 * b1 + sqrt(delta)) / (2 * a1);
	x2 = (-1 * b1 - sqrt(delta)) / (2 * a1);

	//std::cout << x1 << "   2   " << x2 << std::endl;
	y1 = A.a*x1 + A.b;
	y2 = A.a*x2 + A.b;

	//std::cout << y1 << "   3   " << y2 << std::endl;
	X = x1;
	Y = y1;
	//std::cout << X << "   4   " << Y << std::endl;
	Punkt G(X, Y);
	return G;

}
void stosunek(Naboj *Head, double &x, double &y, double X, double Y, int cw)
{
	double v = 0.03;

	if (cw == 1)
	{
		x = x + v * X;
		y = y + v * Y;
		//std::cout << "1" << std::endl;
	}
	else if (cw == 2)

	{
		//std::cout << "2" << std::endl;
		x = x - v * X;
		y = y - v * Y;
	}
	else if (cw == 3)

	{
		//std::cout << "3" << std::endl;
		x = x - v * X;
		y = y - v * Y;
	}
	else if (cw == 4)

	{
		//std::cout << "4" << std::endl;
		x = x + v * X;
		y = y + v * Y;
	}


}

//==========================    Naboj
//stare
/*
Naboj::Naboj()
{
x = 0;
y = 0;
}
Naboj::Naboj(double x, double y, double a, double b, float kat)
{
this->x = x;
this->y = y;
this->a = a;
this->b = b;
this->kat = kat;

Prosta A = rownanie(x, y, a, b);
Punkt XY = wspPkt(A);
double a1 = XY.x * 10000;
double a2 = XY.y * 10000;
int b1 = a1;
int b2 = a2;
a1 = b1 / 10000;
a2 = b2 / 10000;




this->stos1 = a1;
this->stos2 = a2;


if (a>x && b<y)
{
//std::cout << "1" << std::endl;
this->cw = 1;
}
else if (a<x && b<y)
{
//	std::cout << "2" << std::endl;
this->cw = 2;
}
else if (a>x && b>y)
{
//	std::cout << "4" << std::endl;
this->cw = 4;
}
else if (a<x && b>y)
{
//	std::cout << "3" << std::endl;
this->cw = 3;
}




}
double Naboj::poruszaj(Naboj *Head, double &x, double &y, double stos1, double stos2, int cw, float kat)
{
if (Head != NULL)
{


//	///tutaj ify na cwiartki
int v = 1;
if (cw == 1)
{
x = x + v * (stos1 + 1);
y = y - v * (stos2 + 1);
//std::cout << "1" << std::endl;
}
else if (cw == 2)

{
//std::cout << "2" << std::endl;
x = x - v * (stos1 + 1);
y = y - v * (stos2 + 1);
}
else if (cw == 3)

{
//std::cout << "3" << std::endl;
x = x - v * (stos1 + 1);
y = y + v * (stos2 + 1);
}
else if (cw == 4)

{
//std::cout << "4" << std::endl;
x = x + v * (stos1 + 1);
y = y + v * (stos2 + 1);
}


//return 0;


}
return 0;
}
void Naboj::dorzuc(Naboj *&Head, double x, double y, double a, double b, float kat)
{
Naboj*p = new Naboj(x, y, a, b, kat);
Naboj*p1 = Head;
Naboj *p2 = Head;
if (Head == NULL)
{
p->next = NULL;
Head = p;
//std::cout << "1" << std::endl;
}
else
{
while (p1->next != NULL)
{
p2 = p1;
p1 = p1->next;
//std::cout << "2" << std::endl;
}
p->next = p1->next;
p1->next = p;
//std::cout << "3" << std::endl;

}


}
void Naboj::wyswietl(Naboj *Head)
{
Naboj *p = Head;
std::cout << "Head" << "->";
if (Head != NULL)
{

while (p != NULL)
{
std::cout << p->x << "|" << p->y << "|" << p->a << "|" << p->b << "|" << p->kat << "->";
p = p->next;
}
}
std::cout << "NULL" << std::endl;
}
bool Naboj::wyrzuc(Naboj *&Head, Naboj *&wsk)
{
Naboj *p = Head;
Naboj *p1 = p;
Naboj* p2 = p;
if (Head != NULL)
{
if (p == Head)
{
if (p->x < 0 || p->y < 0 || p->x > 800 || p->y > 600)
{
Head = Head->next;
//std::cout << "========" << Head << std::endl;
delete p;
wsk = Head;
return 1;
//p = Head;
}
//p = p->next;
}
else
{

while (p->next != NULL)
{

if (p->x < 0 || p->y < 0 || p->x > 800 || p->y > 600)
{

p1->next = p->next;

delete p;
wsk = Head;
return 1;
}
p1 = p;
p = p->next;
}

}


}
return 0;
//wsk = Head;
/*else
{
if (Head->next == NULL)
{
if (Head->x == 0 || Head->y == 0)
{
Head = Head->next;
delete p;
}
}
}

}
*/
//nowe
Naboj::Naboj()
{

}
Naboj::Naboj(double graczX, double graczY, double myszX, double myszY, sf::Sprite teksturaPocisku)
{


	this->pociskSprite = teksturaPocisku;
	this->pociskSprite.setOrigin(25, 25);
	this->x = graczX;
	this->y = graczY;
	this->kat = atan2(myszY - graczY, myszX - graczX);
	double z = 100;
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


	this->predkoscX = a;
	this->predkoscY = b;





}
void Naboj::dorzuc(Naboj *&Head, double graczX, double graczY, double myszX, double myszY, sf::Sprite teksturaPocisku)
{
	Naboj*p = new Naboj(graczX, graczY, myszX, myszY, teksturaPocisku);
	Naboj*p1 = Head;
	Naboj *p2 = Head;
	if (Head == NULL)
	{
		p->next = NULL;
		Head = p;
		//std::cout << "1" << std::endl;
	}
	else
	{
		while (p1->next != NULL)
		{
			p2 = p1;
			p1 = p1->next;
			//std::cout << "2" << std::endl;
		}
		p->next = p1->next;
		p1->next = p;
		//std::cout << "3" << std::endl;

	}


}
void Naboj::przemiesc(Naboj *&p)
{
	p->x = p->x + p->predkoscX;
	p->y = p->y + p->predkoscY;
}
void Naboj::wyswietl(Naboj *Head)
{
	Naboj *p = Head;
	std::cout << "Head" << "->" << std::endl;
	if (Head != NULL)
	{

		while (p != NULL)
		{
			//std::cout << p->x << "|" << p->y << "|" << p->a << "|" << p->b << "|" << p->kat << "->";
			std::cout <<"|" << p->x << "->";
			p = p->next;
			std::cout << std::endl;
		}
	}
	std::cout << "NULL" << std::endl;
}
void Naboj::kolizjaNaboju(Naboj *&Head, sf::Image podkladMapy)
{
	Naboj *aktualneP = Head;
	Naboj *poprzednieP = Head;
	
		while (aktualneP != NULL)
		{
			if (aktualneP->ograniczeniePocisk(podkladMapy)) // jezeli czarne 
			{
				wyrzuc(Head, poprzednieP, aktualneP);
			}else{
				poprzednieP = aktualneP;
				aktualneP = aktualneP->next;
			}
		}
}


bool Naboj::ograniczeniePocisk(sf::Image podkladMapy)
{
	
	sf::Color kolor = sf::Color::Black;
	//std::cout << this->x << "    " << this->x<< std::endl;
	if (podkladMapy.getPixel(this->x, this->y) == kolor)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Naboj::wyrzuc(Naboj*&Head, Naboj *&poprzednieP, Naboj *&aktualneP)
{
	Naboj *pomocnicze = NULL;
	if (Head == aktualneP)
	{
		pomocnicze = Head;
		Head = Head->next;
		aktualneP = Head;
		poprzednieP = Head;
		delete pomocnicze;
		
	}else{
		poprzednieP->next = aktualneP->next;
		pomocnicze = aktualneP;
		aktualneP = poprzednieP->next;
		delete  pomocnicze;
		
	}
}
//================Punkt
Punkt::Punkt()
{
	this->x = 0;
	this->y = 0;
}
Punkt::Punkt(double x, double y)
{
	this->x = x;
	this->y = y;
}


