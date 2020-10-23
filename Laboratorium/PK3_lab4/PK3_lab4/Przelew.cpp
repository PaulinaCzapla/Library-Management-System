#include "Przelew.h"

Przelew::Przelew(float prowizja_, std::string waluta_) : FormaPlatnosci(prowizja_, waluta_) {}

void Przelew::wykonaj_platnosc()
{
	std::string kom;
	std::cout << " Podaj telefon stacjonarny: ";
	std::cin >> kom;

	Telefonstat telefon(kom);
	if (telefon.sprawdz())
		std::cout << " OK " << std::endl;
	else
		std::cout << " zly numer" << std::endl;
}