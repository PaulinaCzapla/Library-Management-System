#pragma once
#include "Resource.h"


class Book :
	public Resource
{
public:
	Book(std::string, std::string, Date, Date, Date, std::string = "brak", bool = true, Person* = nullptr);
	void create_id(int);
	
};

