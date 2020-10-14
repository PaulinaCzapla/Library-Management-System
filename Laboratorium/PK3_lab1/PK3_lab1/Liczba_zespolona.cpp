#include "Liczba_zespolona.h"
#include <iostream>

int Liczba_zespolona::licznik = 0;

Liczba_zespolona::Liczba_zespolona ( float rez, float imz) 
{
	licznik++;
	IM = imz;
	RE = rez;
	std::cout << " Konstruktor wieloargumentowy zostal wywolany. " << std::endl;
}

Liczba_zespolona::Liczba_zespolona(float rez)
{
	licznik++;
	IM = 0;
	RE = rez;
	std::cout << " Konstruktor jednoargumentowy zostal wywolany. " << std::endl;
}
Liczba_zespolona::Liczba_zespolona()
{
	licznik++;
	IM = 0;
	RE = 0;
	std::cout << " Konstruktor bezargumentowy zostal wywolany. " << std::endl;
}
Liczba_zespolona::Liczba_zespolona(Liczba_zespolona& liczba)
{
	licznik++;
	IM = liczba.IM;
	RE = liczba.RE;
	std::cout << " Konstruktor kopiujacy zostal wywolany. " << std::endl;
}

Liczba_zespolona::~Liczba_zespolona()
{
	Liczba_zespolona::licznik--;
}

void Liczba_zespolona::set_IM(float IM)
{
	this->IM = IM;
}

void Liczba_zespolona::set_RE(float RE)
{
	this->RE = RE;
}

float Liczba_zespolona::get_IM()
{
	return IM;
}

float Liczba_zespolona::get_RE()
{
	return RE;
}

void Liczba_zespolona::wyswietl()
{
	std::cout << " IM=" << this->IM << " RE=" << this->RE<< std::endl;
}

void Liczba_zespolona::pokaz_ile_obiektow()
{
	std::cout << " W programie jest " << licznik << " liczb zespolonych. " << std::endl;
}