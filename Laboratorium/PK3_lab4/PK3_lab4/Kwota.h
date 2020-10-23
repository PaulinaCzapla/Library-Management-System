#pragma once
#include "Walidator.h"
class Kwota :
    public Walidator
{

public:
    Kwota(std::string);
    bool sprawdz();
};

