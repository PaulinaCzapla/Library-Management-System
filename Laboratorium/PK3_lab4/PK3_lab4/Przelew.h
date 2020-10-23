#pragma once
#include "FormaPlatnosci.h"
#include"Telefonstat.h"
class Przelew :
    public FormaPlatnosci
{
public:
	Przelew(float, std::string);
	void wykonaj_platnosc();
};

