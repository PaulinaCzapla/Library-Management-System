#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <conio.h>
#include "Library.h"
#include "Person.h"
#include "List.h"
#include "Node.h"

class Functions
{
public:
	void borrow(Library&, List<Person>&);
	void make_a_return(Library&, List<Person>&);

	Node <Person>* find_user_byID(List<Person>&);
	void add_new_user(List<Person>&);
	void delete_user(List<Person>&);

	void add_new_book(Library&);
	void add_new_cd(Library&);
	void add_new_movie(Library&);
	void delete_resource(Library&);
	Node <Book>* find_book_byID(List<Book>&, std::string);
	Node <CD>* find_cd_byID(List<CD>&, std::string);
	Node <Movie>* find_movie_byID(List<Movie>&, std::string);
	bool search_library(Library&);

	void show_imported_resources(Library&, std::string&);
	void import_resource(Library&, Library&);
};

#endif