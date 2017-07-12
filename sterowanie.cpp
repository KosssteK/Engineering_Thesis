#include "naglowki.h"
#include "sterowanie.h"
#include "postacie.h"
// ==================== MYSZKA =========================

Myszka::Myszka()
{
	this->x = 0;
	this->y = 0;
}
void Myszka::ustaw(double x, double y)
{
	this->x = x;
	this->y = y;

}
void Myszka::ustaw(sf::Vector2i A)
{
	this->x = A.x;
	this->y = A.y;

}
void Myszka::wypisz()
{
	std::cout << this->x << "    " << this->y << std::endl;

}
double Myszka::getX()
{
	return this->x;
}
double Myszka::getY()
{
	return this->y;
}

// ==================== MAPA  ==============================
Mapa::Mapa()
{

}
Mapa::Mapa(sf::Texture podkladMapy)
{
	this->podkladMapy = podkladMapy.copyToImage();
	

}
std::string Mapa::ograniczeniaBok(bohater A)
{
	sf::Color kolor = sf::Color::Black;
	int srodek = 10;
	if (this->podkladMapy.getPixel(A.getX()- srodek,A.getY()) == kolor)
	{
		return "LEFT";
	}
	else if (this->podkladMapy.getPixel(A.getX()+ srodek, A.getY()) == kolor)
	{
		return "RIGHT";
	}
	
	else
	{
		return "1";
	}
}
std::string Mapa::ograniczeniaPion(bohater A)
{
	sf::Color kolor = sf::Color::Black;
	int srodek = 10;
	
	if (this->podkladMapy.getPixel(A.getX(), A.getY() - srodek) == kolor)
	{
		return "UP";
	}
	else if (this->podkladMapy.getPixel(A.getX(), A.getY() + srodek) == kolor)
	{
		return "DOWN";
	}
	else
	{
		return "1";
	}
}