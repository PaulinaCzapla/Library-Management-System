#pragma once
#include "Silnik.h"
#include "Radio.h"
class Samolot
{

public:
	float x;
	float y;
	float  z;

public:
	float paliwo;
	float dystans;
	float wysokosc;

	char* sygnatura;
	//const int masa;
	
	//Silnik psilnik;
	//Radio &radio;

	void set_x(float);
	void set_y(float);
	void set_z(float);

	//Samolot(float, float, float, float, float, float, char*);
};

