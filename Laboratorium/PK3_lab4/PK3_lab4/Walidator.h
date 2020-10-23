#pragma once
#include <iostream>
class Walidator
{
protected:
	std::string tekst;
public:
	Walidator(std::string);
	virtual bool sprawdz() = 0;
};

