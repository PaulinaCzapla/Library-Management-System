#pragma once
#ifndef LIBRARY_H
#define LIBRARY_H
#include "List.h" 


#define LIBRARIES_NUM 3

class Library
{
public:
	Library();
	List <Book>  books;
	List <CD> cds;
	List <Movie> movies;
	~Library() {};
};

#endif