#pragma once
#include "FormaPlatnosci.h"
#include "Telefonkom.h"

class PrzelewPrzyOdbiorze :
	public FormaPlatnosci
{
public:
	PrzelewPrzyOdbiorze(float, std::string);
	void wykonaj_platnosc();
};

