#include "Date.h"

Date::Date(short unsigned int day_, short unsigned int month_, short unsigned int year_)
{
	this->day = day_;
	this->month = month_;
	this->year = year_;
}
Date Date::get_today()
{

}

void Date::set_day(short unsigned int day_)
{
	this->day = day_;
}

void Date::set_month(short unsigned int month_)
{
	this->month = month_;
}

void Date::set_year(short unsigned int year_)
{
	this->year = year_;
}

bool Date::is_late(Date deadline)
{

}

std::ostream& Date::operator<< (std::ostream& output)
{
	std::cout << this->day << "." << this->month << "." << this->year;
	return output;
}

Date& Date::operator- (const Date& date_) const
{

}
