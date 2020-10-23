#pragma once
#include <iostream>
#include <fstream>
class Plik
{
protected:
	std::string nazwa;

public:
	Plik(std::string);
	virtual void odczytaj()=0;
};

