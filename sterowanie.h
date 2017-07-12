#ifndef sterowanie_h
#define sterowanie_h
#include "postacie.h"
class Myszka
{
	double x;
	double y;


public:
	Myszka();
	void ustaw(double x, double y);
	void ustaw(sf::Vector2i A);
	double getX();
	double getY();
	void wypisz();
};

class Mapa
{
	
	sf::Image podkladMapy;

public: 
	Mapa();
	Mapa(sf::Texture podkladMapy);
	std::string ograniczeniaBok(bohater A);
	std::string ograniczeniaPion(bohater A);
};


#endif