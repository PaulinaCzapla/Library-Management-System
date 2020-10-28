#pragma once
#include "dab.h"
#include "MP3.h";
#include "MPG.h"
#include "radiofm.h"

class Dekoder : public DabPlus, public MP3, public MPG, public RadioFM
{
	int moc;
public:
	Dekoder();
	void ustaw_moc(int);
	void wyswietl_moc();

};

