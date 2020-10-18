#pragma once
#include <iostream>
#include "Date.h"
#include "List.h"
class Person
{
	std::string ID;
	std::string name;
	Date birth_date;
	std::string address;
	std::string phone_number;
	
	Person* next;

	List <class Book> * books;
	List <class CD> * cds;
	List <class Movie> * movies;

public:
	void show_books();
	void show_cds();
	void show_movies();
	void show_data();
	

};

