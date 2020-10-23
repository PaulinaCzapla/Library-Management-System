#pragma once
#include "Walidator.h"
class LiczbaRzymska :
    public Walidator
{
 
public:
   LiczbaRzymska(std::string);
    bool sprawdz();
};

