#pragma once
#include <iostream>
class MPG
{
	int kompresja;
	int crc;
	std::string format;
	int moc;

public:
	MPG();
	MPG(int, int, std::string, int);
	void dekoduj();
	void wypisz_format();
};

