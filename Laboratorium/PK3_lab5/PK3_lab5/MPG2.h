#pragma once
#include "MPG.h"
class MPG2 :
    public virtual MPG // dziedziczenie wirtualne jest rozwiązaniem problemu rombu
{
public: 
    MPG2();
};

