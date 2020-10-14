#include "Element_listy.h"
#include <iostream>

Element_listy::Element_listy(Liczba_zespolona& zespolona, Element_listy* nast) : liczba(zespolona), nastepny(nast) {}

Element_listy::Element_listy(Liczba_zespolona& zespolona) : liczba(zespolona), nastepny(nullptr) {}

Element_listy::Element_listy() : liczba(), nastepny(nullptr) {}

Element_listy::Element_listy(Element_listy& element) : liczba(element.liczba), nastepny(element.nastepny) {}

void Element_listy::zmien_nastepny(Element_listy* nastepny)
{
	this->nastepny = nastepny;
}

void Element_listy::wyswietl()
{
	liczba.wyswietl();
}

Element_listy* Element_listy::zwroc_nastepny()
{
	return this->nastepny;
}