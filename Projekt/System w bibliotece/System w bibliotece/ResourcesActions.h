#pragma once
#include "Library.h"
#include "List.h"
#include <conio.h>

class ResourcesActions : public Text
{
public:
	ResourcesActions() {};

	void add_new_book(Library&);
	void add_new_cd(Library&);
	void add_new_movie(Library&);
	void delete_resource(Library&);
	Node <Book>* find_book_byID(List<Book>&, std::string);
	Node <CD>* find_cd_byID(List<CD>&, std::string);
	Node <Movie>* find_movie_byID(List<Movie>&, std::string);
	Node <Book>* find_book_byTitle(List<Book>&, Book&);
	Node <CD>* find_cd_byTitle(List<CD>&, CD&);
	Node <Movie>* find_movie_byTitle(List<Movie>&, Movie&);
};

