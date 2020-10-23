#include "PlikTxt.h"

PlikTxt::PlikTxt(std::string nazwa_) : Plik(nazwa_) {}

void PlikTxt::odczytaj()
{
	std::ifstream plik;
	plik.open(this->nazwa, std::ios::in);

	std::string telkom, telst, kwota, email, liczbarz;

	if(plik.good())
	while (!plik.eof())
	{
		plik >> telkom >> telst >> kwota >> email >> liczbarz;
	}
		
}
