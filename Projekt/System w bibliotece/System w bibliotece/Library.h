#pragma once
#include "List.h"

class Library
{
	List <Book>  books;
	List <CD> cds;
	List <Movie> movies;

public:
	Library();
	void display_books();
	void display_cds();
	void display_movies();
	void add_book();
	void add_cd();
	void add_movie();
	void delete_book();
	void delete_cd();
	void delete_movie();

	~Library();

};

