#pragma once
#include "Liczba_zespolona.h"

class Element_listy
{
	Liczba_zespolona liczba;
	Element_listy* nastepny;
	
public:
	Element_listy(Liczba_zespolona&, Element_listy*);
	Element_listy(Liczba_zespolona&);
	Element_listy();
	Element_listy(Element_listy&);
	void zmien_nastepny(Element_listy*);
	void wyswietl();
	Element_listy* zwroc_nastepny();
};

