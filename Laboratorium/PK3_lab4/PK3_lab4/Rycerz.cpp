#include "Rycerz.h"

Rycerz::Rycerz(std::string imie_) : Bohater(imie_) {}

void Rycerz::przedstaw_sie()
{
	std::cout << " Jam jest" << this->imie << " Wielki. Jestem rycerzem. " << std::endl;
}
