#include "dab.h"


DabPlus::DabPlus()
{
	this->crc = 0;
	this->format = "";
	this->kompresja = 0;
	this->moc = 0;
	std::cout << " konstruktor dab+" << std::endl;
}

DabPlus::DabPlus(int kompresja_, int crc_, std::string format_, int moc_)
{
	this->kompresja = kompresja_;
	this->crc = crc_;
	this->format = format_;
	this->moc = moc_;

	std::cout << " konstruktor wieloargumentowy dab+ " << std::endl;
}

void DabPlus::dekoduj()
{
	std::cout << " crc: " << this->crc << " kompresja: " << this->kompresja << " moc: " << this->moc << " format: " << this->format << std::endl;
}
void DabPlus::wypisz_format()
{
	std::cout << " Format: " << format << std::endl;
}