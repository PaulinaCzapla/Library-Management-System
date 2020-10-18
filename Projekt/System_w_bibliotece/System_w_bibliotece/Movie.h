#pragma once
#include "Resource.h"

class Movie :
	public Resource
{
public:
	Movie(std::string, std::string, Date, Date, Date, std::string = "brak", bool = true, Person* = nullptr);
	void create_id(int);
};

