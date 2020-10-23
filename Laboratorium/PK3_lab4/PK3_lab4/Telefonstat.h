#pragma once
#include "Walidator.h"
class Telefonstat :
    public Walidator
{
public:
    Telefonstat(std::string);
    bool sprawdz();
};

