#pragma once
#include <iostream>
#include "Date.h"
#include "Person.h"

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
	virtual void show() =0;
	void change_availability(bool);
	virtual void create_id()=0;
	Resource& operator=(const Resource&);
	bool operator==(const std::string&);
	std::ostream& operator<< (std::ostream& );

};

