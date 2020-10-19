#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "Date.h"
#include "List.h"
#include "Text.h"
//#include "Movie.h"
//#include "CD.h"
//#include "Book.h"
#include "Borrowed.h"
class Person
{
	friend std::ostream& operator<<(std::ostream& output, Person const& data);
	std::string ID;
	std::string name;
	Date birth_date;
	std::string address;
	std::string phone_number;

	List <Borrowed<Book>*>* books;
	List <Borrowed<CD>*>* cds;
	List <Borrowed<Movie>*>* movies;

public:
	Person(std::string, std::string, Date, std::string = "brak", std::string = "brak", List <Borrowed<Book>*>* = nullptr, List <Borrowed<CD>*>* = nullptr, List <Borrowed<Movie>*>* = nullptr);
//operator =
};

#endif