#pragma once
#include "Zwierzatko.h"
class Tablica_dwm_zwierzatka
{

	int k;
	int w;
	Zwierzatko** tab;

public:
	Tablica_dwm_zwierzatka(int, int);
	Tablica_dwm_zwierzatka();
	void dodaj(Zwierzatko, int, int);
	Zwierzatko** zwroc_wskaznik();

	Tablica_dwm_zwierzatka& operator=(Tablica_dwm_zwierzatka&& other)
	{
		if (this != &other)
		{
			for (int i = 0; i < w; i++)
				delete[] tab[i];

			delete[] * tab;

			this->k = other.k;
			this->w = other.w;

			this->tab = other.tab;

			other.k = 0;
			other.w = 0;
		}
		return *this;
	}

	Tablica_dwm_zwierzatka(Tablica_dwm_zwierzatka&& other);
	~Tablica_dwm_zwierzatka();
	Zwierzatko wyswietl(int, int);
};

