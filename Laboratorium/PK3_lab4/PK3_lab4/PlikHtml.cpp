#include "PlikHtml.h"

PlikHtml::PlikHtml(std::string nazwa_) : Plik(nazwa_) {}

void PlikHtml::odczytaj()
{
	std::ifstream plik;
	plik.open(this->nazwa, std::ios::in);

	std::string telkom, telst, kwota, email, liczbarz;
	char znak;

	if (plik.good())
		while (!plik.eof())
		{
			plik >> znak;
			if (znak == '<')
			{
				while (!plik.eof())
				{
					plik >> znak;
					if (znak == '>')
						break;
				}
			}
			plik >> telkom >> telst >> kwota >> email >> liczbarz;
			break;
		}
}
