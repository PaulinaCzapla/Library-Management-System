#include "MP3.h"


MP3::MP3()
{
	this->crc = 0;
	this->format = "";
	this->kompresja = 0;
	this->moc = 0;
	std::cout << " konstruktor MP3" << std::endl;
}

MP3::MP3(int kompresja_, int crc_, std::string format_, int moc_)
{
	this->kompresja = kompresja_;
	this->crc = crc_;
	this->format = format_;
	this->moc = moc_;

	std::cout << " konstruktor wieloargumentowy MP3 " << std::endl;
}

void MP3::dekoduj()
{
	std::cout << " crc: " << this->crc << " kompresja: " << this->kompresja << " moc: " << this->moc << " format: " << this->format << std::endl;
}
void MP3::wypisz_format()
{
	std::cout << " Format: " << format << std::endl;
}