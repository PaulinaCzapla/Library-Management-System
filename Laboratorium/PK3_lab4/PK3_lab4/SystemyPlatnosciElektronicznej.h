#pragma once
#include "FormaPlatnosci.h"
#include "Telefonstat.h"

class SystemyPlatnosciElektronicznej :
    public FormaPlatnosci
{
public:
    SystemyPlatnosciElektronicznej(float, std::string);
    void wykonaj_platnosc();
};

