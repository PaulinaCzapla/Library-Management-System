#pragma once
#include "MPG.h"
#include "MPG2.h"
class MPG4 :
    public virtual MPG, public MPG2 // dziedziczenie wirtualne jest rozwi¹zaniem problemu rombu
{
public:
    MPG4();
};

