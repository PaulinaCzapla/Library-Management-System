#pragma once
#include "Date.h"


#define PRICE 7

template<typename T>
class Borrowed
{
	T data;
	Date borrow_date;
	Date deadline;

public:
	Borrowed(T, Date, Date);
	Borrowed();
	void display();
	int count_fine();
};

