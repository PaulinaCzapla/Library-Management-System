#pragma once
#include <iostream>
class MP3
{
	int kompresja;
	int crc;
	std::string format;
	int moc;

public:
	MP3();
	MP3(int, int, std::string, int);
	void dekoduj();
	void wypisz_format();
};

