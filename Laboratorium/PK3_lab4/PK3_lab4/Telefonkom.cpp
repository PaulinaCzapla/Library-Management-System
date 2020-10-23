#include "Telefonkom.h"

Telefonkom::Telefonkom(std::string tekst_) : Walidator(tekst_) {}

bool Telefonkom::sprawdz()
{
	int i = 0;

	if (this->tekst[0] == '0')
		return false;

	if (this->tekst[0] == '+')
	{
		if ((this->tekst[i + 1] < 48 || this->tekst[i + 1]>57) && (this->tekst[i + 2] < 48 || this->tekst[i + 2]>57))
			return false;
		else
			i = 3;
	}

	if (tekst.length() - 9 - i == 0)
		for (i; i < tekst.length(); i++)
		{
			if (this->tekst[i] < 48 || this->tekst[i]>57)
				return false;
		}
	else
		return false;

	return true;
}