#pragma once
#include "MPG4.h"

class Odtwarzacz: public MPG2, public MPG4 // wystêpuje problem rombu
{
public:
	Odtwarzacz();
	void dekoduj();
};

