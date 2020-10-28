#pragma once
#include <iostream>
class DabPlus
{
	int kompresja;
	int crc;
	std::string format;
	int moc;

public:
	DabPlus();
	DabPlus(int, int, std::string,int);
	void dekoduj();
	void wypisz_format();
};

