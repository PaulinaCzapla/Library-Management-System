#pragma once
#include "Date.h"
#include "Library.h"

#define PRICE 7


class Borrowed
{
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
};

