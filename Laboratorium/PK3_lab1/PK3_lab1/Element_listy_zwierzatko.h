#pragma once
#include "Zwierzatko.h"
class Element_listy_zwierzatko
{
	Zwierzatko zwierzatko;
	Element_listy_zwierzatko* nastepny;

public:
	Element_listy_zwierzatko(Zwierzatko&, Element_listy_zwierzatko*);
	Element_listy_zwierzatko(Zwierzatko&);
	Element_listy_zwierzatko();
	Element_listy_zwierzatko(Element_listy_zwierzatko&);
	void zmien_nastepny(Element_listy_zwierzatko*);
	void wyswietl();
	Element_listy_zwierzatko* zwroc_nastepny();
};

