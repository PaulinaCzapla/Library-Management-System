#pragma once

#include <iostream>
class Bohater
{
protected:
	std::string imie;

public:
	Bohater(std::string);
	virtual void przedstaw_sie() = 0;

};

