#pragma once
#include "Plik.h"
class PlikHtml :
    public Plik
{
public:
    PlikHtml(std::string);
    void odczytaj();
};

