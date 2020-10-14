#include "Tablica_dwm_zwierzatka.h"

#include <iostream>

Tablica_dwm_zwierzatka::Tablica_dwm_zwierzatka(int kk, int ww) : k(kk), w(ww)
{
	tab = new Zwierzatko * [ww];
	for (int i = 0; i < ww; i++)
		tab[i] = new Zwierzatko[kk];
}

Tablica_dwm_zwierzatka::Tablica_dwm_zwierzatka() : tab(nullptr), w(0), k(0) {}

Tablica_dwm_zwierzatka::Tablica_dwm_zwierzatka(Tablica_dwm_zwierzatka&& other) : tab(nullptr), w(0), k(0)
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


void Tablica_dwm_zwierzatka::dodaj(Zwierzatko zesp, int ww, int kk)
{
	tab[ww][kk] = zesp;
}

Zwierzatko** Tablica_dwm_zwierzatka::zwroc_wskaznik()
{
	return tab;

}

Tablica_dwm_zwierzatka::~Tablica_dwm_zwierzatka()
{
	for (int i = 0; i < w; i++)
		delete[] tab[i];

	delete[] * tab;
}
Zwierzatko Tablica_dwm_zwierzatka::wyswietl(int ww, int kk)
{
	return tab[ww][kk];
}