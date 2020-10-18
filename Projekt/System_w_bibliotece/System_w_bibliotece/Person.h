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
	

	List <Book*> * books;
	List <CD*> * cds;
	List <Movie*> * movies; //listy wskaŸników?

public:
	Person(std::string, std::string, Date, std::string = "brak", std::string = "brak", List <Book*>* = nullptr, List <CD*>* = nullptr, List <Movie*>* = nullptr);
	std::ostream& operator<< (std::ostream&);
	

};

