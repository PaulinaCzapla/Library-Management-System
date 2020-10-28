#pragma once
#include<iostream>
class RadioFM
{
	int kompresja;
	int crc;
	std::string format;
	int moc;

public:
	RadioFM();
	RadioFM(int, int, std::string, int);
	void dekoduj();
	void wypisz_format();
};

