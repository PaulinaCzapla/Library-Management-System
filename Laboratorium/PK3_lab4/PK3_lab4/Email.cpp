#include "Email.h"

Email::Email(std::string tekst_) : Walidator(tekst_) {}

bool Email::sprawdz()
{
	bool at = false;
	for (int i = 0; i < tekst.length(); i++)
	{
		if (this->tekst[i] == '@' && i != 0)
			at = true;

		if (this->tekst[i] == '.' && at == true)
			return true;
	}
	return false;
}