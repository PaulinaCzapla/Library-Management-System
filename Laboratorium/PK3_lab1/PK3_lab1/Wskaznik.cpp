#include "Wskaznik.h"
#include <iostream>


Wskaznik::Wskaznik(Liczba_zespolona liczba)
{
	this->liczba = new Liczba_zespolona;
	*(this->liczba) = liczba;
}

Wskaznik::Wskaznik()
{
	liczba = nullptr;
}

Wskaznik::Wskaznik(Wskaznik&& other) : liczba(nullptr)
{
	this->liczba = other.liczba;
	this->liczba->set_IM( other.liczba->get_IM());
	this->liczba->set_RE( other.liczba->get_RE());

	other.liczba = nullptr;

}

Wskaznik::~Wskaznik()
{
	delete[] this->liczba;
}

void Wskaznik::wyswietl()
{
	liczba->wyswietl();
}

