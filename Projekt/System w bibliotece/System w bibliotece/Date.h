#pragma once
#include <iostream>
#include <string>

class Date
{
	protected:
	short unsigned int day;
	short unsigned int month;
	short unsigned int year;

public:
	Date(short unsigned int = 0, short unsigned int = 0, short unsigned int = 0);
	Date get_today();
	void set_day(short unsigned int);
	void set_month(short unsigned int);
	void set_year(short unsigned int);
	bool is_late(Date);
	std::ostream& operator<< (std::ostream&);
	Date& operator- (const Date&) const;
};

