#include "Zlodziej.h"


Zlodziej::Zlodziej(std::string imie_) : Bohater(imie_) {}

void Zlodziej::przedstaw_sie()
{
	std::cout << " Mam na imie " << this->imie << ". Jestem polym zlodziejem! " << std::endl;
}
