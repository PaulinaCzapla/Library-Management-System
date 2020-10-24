#include "Date.h"

Date::Date(short unsigned int day_, short unsigned int month_, short unsigned int year_)
{
	this->day = day_;
	this->month = month_;
	this->year = year_;
}

Date::Date(std::string date_)
{
		this->day = (date_[0] - '0') * 10 + (date_[1] - '0');
		this->month = (date_[3] - '0') * 10 + (date_[4] - '0');
		this->year = (date_[6] - '0') * 1000 + (date_[7] - '0') * 100 + (date_[8] - '0') * 10 + (date_[9] - '0');
}

Date::Date()
{
	SYSTEMTIME time;
	GetSystemTime(&time);

	this->day = time.wDay;
	this->month = time.wMonth;
	this->year = time.wYear;
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

//bool Date::is_late(Date deadline)
//{
//
//}

std::ostream& Date::operator<< (std::ostream& output)
{
	std::cout << this->day << "." << this->month << "." << this->year;
	return output;
}

int Date::operator- (const Date& other) const //zwraca ró¿nicê w dniach
{
	int days, months, years, sum = 0, months_sign = 1, years_sign = 1, monthprev = 0, monthnext = 0;

	int daysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };


	years = this->year - other.year;
	months = this->month - other.month;
	days = this->day - other.day;

	if (years < 0 || years >0)//12.10.2019  -  18.10.2020   
	{
		(years > 0 ? years_sign = 1 : years_sign = -1);


		for (int i = 0; i < years; i++)
			sum += 365;

		for (int i = 0; i < 12 - this->month; i++)
			monthprev += daysInMonth[this->month - 1 + i];
			
		for (int i = 0; i < other.month; i++)
			monthnext += daysInMonth[other.month - 1 - i];

		return sum - monthprev + monthnext;

	}
	else if (years == 0)  //12.10.2020  -  18.10.2020   
	{
		if (months == 0) //12.10.2020  -  18.10.2020   
			return days;

		if (months > 0 || months < 0) //12.11.2020 - 18.10.2020 
		{
			(months > 0 ? months_sign = 1 : months_sign = -1);

			for (int i = 0; i < months; i++)
				sum += daysInMonth[this->month - 1 + i];

			return (sum - this->day + other.day) * months_sign;
		}
	}
}

Date& Date::operator=(const Date& other)
{
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;

	return *this;
}

	//Date::~Date()
	//{

	//}
