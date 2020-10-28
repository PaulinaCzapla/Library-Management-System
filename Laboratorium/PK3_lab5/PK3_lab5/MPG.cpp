#include "MPG.h"


MPG::MPG()
{
	this->crc = 0;
	this->format = "";
	this->kompresja = 0;
	this->moc = 0;
	std::cout << " konstruktor MPG" << std::endl;
}

MPG::MPG(int kompresja_, int crc_, std::string format_, int moc_)
{
	this->kompresja = kompresja_;
	this->crc = crc_;
	this->format = format_;
	this->moc = moc_;

	std::cout << " konstruktor wieloargumentowy MPG " << std::endl;
}

void MPG::dekoduj()
{
	std::cout << " crc: " << this->crc << " kompresja: " << this->kompresja << " moc: " << this->moc << " format: " << this->format << std::endl;
}
void MPG::wypisz_format()
{
	std::cout << " Format: " << format << std::endl;
}