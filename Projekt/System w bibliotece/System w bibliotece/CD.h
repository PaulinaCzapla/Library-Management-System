#pragma once
#include "Resource.h"
class CD :
	public Resource
{
public:
	CD(std::string, std::string, Date, Date, Date, std::string = "brak", bool = true, Person* = nullptr);	
	void create_id(int);
};

