#pragma once
#ifndef CD_H
#define CD_H
#include "Resource.h"
class CD :
	public Resource
{
public:
	CD(std::string, std::string, Date, std::string = "brak", bool = true);	
	CD(int, std::string, Date, std::string = "brak", bool = true);
	CD();
	void create_id(int);
	CD& operator=(const CD&);
	~CD();
};

#endif