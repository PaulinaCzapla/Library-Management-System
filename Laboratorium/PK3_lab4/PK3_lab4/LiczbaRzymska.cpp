#include "LiczbaRzymska.h"

LiczbaRzymska::LiczbaRzymska(std::string tekst_) : Walidator(tekst_) {}

bool LiczbaRzymska::sprawdz()
{
	
	for (int i = 0; i < tekst.length(); i++)
	{
		if (this->tekst[i] != 'X' && this->tekst[i] != 'V' && this->tekst[i] != 'I' && this->tekst[i] != 'D' && this->tekst[i] != 'C' && this->tekst[i] != 'L' &&  this->tekst[i] != 'M')
			return false;
	}
	return true;
}