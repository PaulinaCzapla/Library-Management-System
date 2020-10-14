#pragma once
#include "Liczba_zespolona.h"

class Wskaznik
{
	Liczba_zespolona* liczba;
public:
	Wskaznik(Liczba_zespolona);
	Wskaznik(Wskaznik&&);
	Wskaznik();
	~Wskaznik();
	Wskaznik& operator=(Wskaznik&& other)
	{
		if (this != &other)
		{
			delete liczba;

			this->liczba = other.liczba;
			this->liczba->set_IM(other.liczba->get_IM());
			this->liczba->set_RE(other.liczba->get_RE());

			other.liczba= nullptr;
			
			return *this;
		}

	}
	void wyswietl();

};

