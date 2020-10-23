#pragma once
#include <iostream>
#include "Kwota.h"

class FormaPlatnosci
{
protected:
	float kwota;
	float prowizja;
	std::string waluta;

public:
	FormaPlatnosci(float, std::string);
	virtual void wykonaj_platnosc()=0;
	void nalicz_oplate(std::string);
};

