#pragma once
#include "Element_listy.h"

class Lista
{
	Element_listy* head;
	int licznik;

public: 
	Lista();
	~Lista();
	void dodaj(Element_listy* element);
	void usun(Element_listy* element);
	void wypisz();
};

