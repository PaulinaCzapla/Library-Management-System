#pragma once
#ifndef LIBRARY_H
#define LIBRARY_H
#include "List.h" //node


#define LIBRARIES_NUM 3

class Library
{
public:
	Library();
	List <Book>  books;
	List <CD> cds;
	List <Movie> movies;

	//Library();
	//void display_books();
	//void display_cds();
	//void display_movies();
	//void add_book(Node<Book> *);
	//void add_cd(Node<CD>*);
	//void add_movie(Node<Movie>*);
	//void delete_book();
	//void delete_cd();
	//void delete_movie();

//	~Library();

};

#endif