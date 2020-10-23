#include "Mag.h"

Mag::Mag(std::string imie_) : Bohater(imie_) {}

void Bohater::przedstaw_sie()
{
	std::cout << " Zwa mnie... " << this->imie << ". Jestem czarodziejem. Pokazac ci sztuczke? " << std::endl;
}

