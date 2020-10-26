#pragma once
#ifndef BORROWED_H
#define BORROWED_H

#include "Date.h"
#include "Library.h" // list node
//#include "List.cpp"
//#include "Node.cpp"
#define PRICE 7
#define BORROW_TIME 21

class Borrowed
{
	friend std::ostream& operator<< (std::ostream&, Borrowed&);
	std::string resource_ID;
	Date borrow_date;
	Date deadline;

public:
	Borrowed(std::string, Date, Date);
	Borrowed();
	void display(Library*);
	std::string get_resource_ID();
	Date get_borrow_date();
	Date get_deadline();
	int count_fine();
	bool operator==(const std::string&);
};
#endif
