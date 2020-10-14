#pragma once
#include "Liczba_zespolona.h"
class Tablica_dwuwymiarowa
{
	int k;
	int w;
	Liczba_zespolona ** tab;

public:
	Tablica_dwuwymiarowa(int, int);
	Tablica_dwuwymiarowa();
	void wyswietl();
	void dodaj (Liczba_zespolona, int, int);
	Liczba_zespolona** zwroc_wskaznik();

	Tablica_dwuwymiarowa& operator=(Tablica_dwuwymiarowa&& other)
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

	Tablica_dwuwymiarowa(Tablica_dwuwymiarowa&& other);
	~Tablica_dwuwymiarowa();
};

