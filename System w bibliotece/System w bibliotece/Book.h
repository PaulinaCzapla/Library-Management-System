#pragma once
#ifndef BOOK_H
#define BOOK_H
#include "Resource.h"

class Book :
	public Resource
{
public:
	Book(std::string, std::string, Date,std::string = "brak", bool = true);
	Book(int, std::string, Date, std::string = "brak", bool = true);
	Book();
	void create_id(int);
	Book& operator=(const Book&);
	~Book();
};

#endif