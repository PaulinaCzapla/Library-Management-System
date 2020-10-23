#pragma once
#include "Walidator.h"
class Email :
    public Walidator
{
public:
    Email(std::string);
    bool sprawdz();
};

