#pragma once
#include <iostream>
#include <string>
#include "Date.h"
#include "Person.h"
#include "Text.h"
#include "List.h"



class Resource //klasa abstrakcyjna
{
protected:
	std::string ID;
	std::string authors_name;
	std::string title;
	Date release_date;
	bool is_available;


	Person* borrower;
	Date borrow_date;
	Date deadline;

public:
	Resource(std::string, std::string, Date, Date, Date, std::string ="brak", bool = true, Person* = nullptr );
	void change_availability(bool);
	virtual void create_id(int)=0;
	Resource& operator=(const Resource&);
	bool operator==(const std::string&);
	std::ostream& operator<< (std::ostream& );

};

