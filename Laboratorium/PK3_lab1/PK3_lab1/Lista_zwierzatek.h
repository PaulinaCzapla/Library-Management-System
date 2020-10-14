#pragma once
#include "Element_listy_zwierzatko.h"

class Lista_zwierzatek
{
	Element_listy_zwierzatko* head;
	int licznik;

public:
	Lista_zwierzatek();
	~Lista_zwierzatek();
	void dodaj(Element_listy_zwierzatko* element);
	void usun(Element_listy_zwierzatko* element);
	void wypisz();
	void wyswietl(Zwierzatko* zwierzatko);
};

