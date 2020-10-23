#include "Kwota.h"

Kwota::Kwota(std::string tekst_) : Walidator(tekst_) {}

bool Kwota::sprawdz()
{
	for (int i = 0; i < tekst.length(); i++)
	{
		if (this->tekst[i] >= 48 && this->tekst[i] <= 57)
			continue;
		else
			if (this->tekst[i] == ',')
			{
				if (tekst.length() - i-1 <= 2)
					if ((this->tekst[i + 1] >= 48 && this->tekst[i + 1] <= 57) && (this->tekst[i + 2] >= 48 && this->tekst[i + 2] <= 57))
						return true;
					else
						return false;
				else
					return false;
			}
			else
				return false;
	}
	return true;

}