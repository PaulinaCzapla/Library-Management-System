#pragma once
#include "MPG4.h"

class Odtwarzacz: public MPG2, public MPG4 // wyst�puje problem rombu
{
public:
	Odtwarzacz();
	void dekoduj();
};

