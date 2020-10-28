#include "dekoder.h"

Dekoder::Dekoder()
{
	this->moc = 0;
	std::cout << " konstruktor dekoder" << std::endl;
}
void Dekoder::ustaw_moc(int moc_)
{
	this->moc = moc_;
}
void Dekoder::wyswietl_moc()
{
	std::cout << " Moc: " <<moc<< std::endl;
}