#pragma once
#include "List.h"

class Library
{
	List <class Book> * books;
	List <class CD>* cds;
	List <class Movie>* movies;

public:
	void show_books();
	void show_CDs();
	void show_Movies();
};

