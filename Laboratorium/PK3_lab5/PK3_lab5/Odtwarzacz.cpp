#include "Odtwarzacz.h"

Odtwarzacz::Odtwarzacz()
{
	std::cout << " konstruktor odtwarzacz " << std::endl;
}
void Odtwarzacz::dekoduj()
{
	MPG::dekoduj();
	MPG2::dekoduj();
	MPG4::dekoduj();
}