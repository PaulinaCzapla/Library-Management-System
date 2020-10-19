#pragma once
#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>
#include <windows.h>
#include <winbase.h>

class Date
{
	friend std::ostream& operator<< (std::ostream& output, Date const& date);
	protected:
	short unsigned int day;
	short unsigned int month;
	short unsigned int year;

public:
	Date(short unsigned int, short unsigned int , short unsigned int );
	Date();
	void set_day(short unsigned int);
	void set_month(short unsigned int);
	void set_year(short unsigned int);
	//bool is_late(Date);
	std::ostream& operator<< (std::ostream&);
	int operator- (const Date&) const;
	Date& operator=(const Date&);
	//~Date();
};

#endif
