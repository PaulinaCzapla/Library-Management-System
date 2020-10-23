#include "FormaPlatnosci.h"

FormaPlatnosci::FormaPlatnosci(float prowizja_, std::string waluta_)
{
	this->kwota = 0;
	this->prowizja = prowizja_;
	this->waluta = waluta_;
}

void FormaPlatnosci::nalicz_oplate(std::string kwota_)
{
	Kwota kw(kwota_);
	if (kw.sprawdz())
	{
		float f_kwota = atof(kwota_.c_str());

		this->kwota = f_kwota + f_kwota * this->prowizja / 100;
	}
	else
		std::cout << " Bledna kwota. " << std::endl;
}