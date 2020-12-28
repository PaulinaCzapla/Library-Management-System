#pragma once
#ifndef MOVIE_H
#define MOVIE_H
#include "Resource.h"

class Movie :
	public Resource
{
public:
	Movie(std::string, std::string, Date, std::string = "brak", bool = true);
	Movie(int, std::string, Date, std::string = "brak", bool = true);
	Movie();
	void create_id(int);
	Movie& operator=(const Movie&);
	~Movie();
};

#endif