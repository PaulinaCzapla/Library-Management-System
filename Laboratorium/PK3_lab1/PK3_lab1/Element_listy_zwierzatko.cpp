#include "Element_listy_zwierzatko.h"

#include <iostream>

Element_listy_zwierzatko::Element_listy_zwierzatko(Zwierzatko& zespolona, Element_listy_zwierzatko* nast) : zwierzatko(zespolona), nastepny(nast) {}

Element_listy_zwierzatko::Element_listy_zwierzatko(Zwierzatko& zespolona) : zwierzatko(zespolona), nastepny(nullptr) {}

Element_listy_zwierzatko::Element_listy_zwierzatko() : zwierzatko(), nastepny(nullptr) {}

Element_listy_zwierzatko::Element_listy_zwierzatko(Element_listy_zwierzatko& element) : zwierzatko(element.zwierzatko), nastepny(element.nastepny) {}

void Element_listy_zwierzatko::zmien_nastepny(Element_listy_zwierzatko* nastepny)
{
	this->nastepny = nastepny;
}

void Element_listy_zwierzatko::wyswietl()
{
	for (int i = 0; i < strlen(zwierzatko.zwroc_zwierzatko()); i++)
		std::cout << zwierzatko.zwroc_zwierzatko()[i];
	
	std::cout << std::endl;
}

Element_listy_zwierzatko* Element_listy_zwierzatko::zwroc_nastepny()
{
	return this->nastepny;
}

