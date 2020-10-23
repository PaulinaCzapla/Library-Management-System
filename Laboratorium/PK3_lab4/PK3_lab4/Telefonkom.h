#pragma once
#include "Walidator.h"
class Telefonkom :
    public Walidator
{
public:
    Telefonkom(std::string);
    bool sprawdz();
};

