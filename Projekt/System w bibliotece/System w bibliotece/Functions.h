#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <conio.h>
#include "Library.h"
#include "Person.h"

class Functions
{
public:
	void borrow(Library*, List<Person>&);
};

#endif