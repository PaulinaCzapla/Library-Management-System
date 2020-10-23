#include "PrzelewPrzyOdbiorze.h"

PrzelewPrzyOdbiorze::PrzelewPrzyOdbiorze(float prowizja_ , std::string waluta_) : FormaPlatnosci( prowizja_, waluta_) {}

void PrzelewPrzyOdbiorze::wykonaj_platnosc()
{
	std::string kom;
	std::cout << " Podaj telefon komorkowy: ";
	std::cin >> kom;

	Telefonkom telefon(kom);
	if (telefon.sprawdz())
		std::cout << " OK " << std::endl;
	else
		std::cout << " zly numer" << std::endl;
}

