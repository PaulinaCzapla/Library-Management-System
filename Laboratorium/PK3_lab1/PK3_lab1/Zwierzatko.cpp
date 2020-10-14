#include "Zwierzatko.h"
#include <cstring>
#include <iostream>

int Zwierzatko::licznik = 0;


Zwierzatko::Zwierzatko(char * zwierzatko_) 
{
	licznik++;
	this->numer = licznik;
	this->zwierzatko = new char[strlen(zwierzatko_)+1];
	strcpy_s(zwierzatko, strlen(zwierzatko_) + 1,  zwierzatko_);

	std::cout << " Konstruktor jednoargumentowy zostal wywolany. " << std::endl;
}
Zwierzatko::Zwierzatko()
{
	licznik++;
	this->numer = licznik;
	const char* krolik = "krolik";
	this->zwierzatko = new char[strlen(krolik) + 1];
	strcpy_s ( zwierzatko,strlen(krolik)+1, krolik);

	std::cout << " Konstruktor bezargumentowy zostal wywolany. " << std::endl;
}
Zwierzatko::Zwierzatko(Zwierzatko& zwierzatko_)
{
	licznik++;
	this->numer = licznik;
	this->zwierzatko = new char[strlen(zwierzatko_.zwierzatko)];
	strcpy_s( zwierzatko, strlen(zwierzatko_.zwierzatko) + 1, zwierzatko_.zwierzatko);

	std::cout << " Konstruktor kopiujacy zostal wywolany. " << std::endl;
}


Zwierzatko::~Zwierzatko()
{
	Zwierzatko::licznik--;
	delete[] zwierzatko;
}

void Zwierzatko::zmien_zwierzatko(char* zwierzatko_)
{
	delete[] zwierzatko;
	char* zwierzatko = new char[strlen(zwierzatko_) + 1];
	strcpy_s(zwierzatko, strlen(zwierzatko_) + 1, zwierzatko_);
}


char* Zwierzatko::zwroc_zwierzatko()
{
	return zwierzatko;
}

int Zwierzatko::zwroc_numer()
{
	return numer;
}

