#include "Tablica_dwuwymiarowa.h"
#include <iostream>

Tablica_dwuwymiarowa::Tablica_dwuwymiarowa(int kk, int ww) : k(kk), w(ww)
{
	tab = new Liczba_zespolona * [ww];
	for (int i = 0; i < ww; i++)
		tab[i] = new Liczba_zespolona[kk];
}

Tablica_dwuwymiarowa::Tablica_dwuwymiarowa() : tab(nullptr), w(0), k(0) {}

Tablica_dwuwymiarowa::Tablica_dwuwymiarowa(Tablica_dwuwymiarowa&& other) : tab(nullptr), w(0), k(0)
{
	this->k = other.k;
	this->w = other.w;

	this->tab = other.tab;

	other.k = 0;
	other.w = 0;

	for (int i = 0; i < other.w; i++)
		delete[] other.tab[i];

	delete[] * other.tab;

}


void Tablica_dwuwymiarowa::wyswietl()
{
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < k; j++)
		{
			tab[i][j].wyswietl();
			std::cout << std::endl;
		}
			
	}
}
void Tablica_dwuwymiarowa::dodaj( Liczba_zespolona zesp, int ww, int kk)
{
	tab[ww][kk] = zesp;
}

Liczba_zespolona** Tablica_dwuwymiarowa::zwroc_wskaznik()
{
	return tab;

}

Tablica_dwuwymiarowa::~Tablica_dwuwymiarowa()
{
	for (int i = 0; i < w; i++)
		delete[] tab[i];

	delete[] * tab;
}