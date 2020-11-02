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

void Date::set_date_from_string(std::string date_)
{
	this->day = (date_[0] - '0') * 10 + (date_[1] - '0');
	this->month = (date_[3] - '0') * 10 + (date_[4] - '0');
	this->year = (date_[6] - '0') * 1000 + (date_[7] - '0') * 100 + (date_[8] - '0') * 10 + (date_[9] - '0');
}

std::string Date::date_to_string()
{
	std::string tmp;
	if (this->day < 10)
		tmp = '0' + std::to_string(this->day);
	else
		tmp =std::to_string(this->day);

	if (this->month < 10)
		tmp = tmp + "-0" + std::to_string(this->month);
	else
		tmp =tmp +'-' + std::to_string(this->month);

	return tmp + '-' + std::to_string(this->year);
}

std::string Date::year_to_string()
{
	return std::to_string(this->year);
}

bool Date::validate()
{
	int daysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (this->day <= daysInMonth[this->month] && 0 < this->month <= 12)
		return true;
	else
		return false;
}

bool Date::check_string(std::string date)
{
	if (date.length() == 10)
		if (date[2] == '.' || date[2] == '-' && date[5] == '.' || date[5] == '-')
			if (isdigit(date[0]) && isdigit(date[1]) && isdigit(date[3]) && isdigit(date[4]) && isdigit(date[6]) && isdigit(date[7]) && isdigit(date[8]) && isdigit(date[9]))
				return true;
	return false;
}

int Date::operator- (const Date& other) const //zwraca ró¿nicê w dniach
{
	int days, months, years, sum = 0, months_sign = 1, years_sign = 1, monthprev = 0, monthnext = 0;

	int daysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };


	years = this->year - other.year;
	months = this->month - other.month;
	days = this->day - other.day;

	if (years < 0 || years >0)
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
	else if (years == 0)  
	{
		if (months == 0)  
			return days;

		if (months > 0 || months < 0) 
		{
			(months > 0 ? months_sign = 1 : months_sign = -1);

			for (int i = 0; i < months; i++)
				sum += daysInMonth[this->month - 1 + i];

			return (sum - this->day + other.day) * months_sign;
		}
	}
}

Date Date::operator+ (const int& other) const
{
	int daysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	int tmp, diff= 0, months=0, year = this->year;
	tmp = this->day + other;

	Date date;
	months = this->month;
	if (tmp > daysInMonth[this->month])
	{
		for (int i = this->month; ; i++)
		{
			if (i > 12)
			{
				i = 1;
				year++;
				months = 0;
			}
			tmp -= daysInMonth[i-1];
			months++;

			if (daysInMonth[i-1] >= tmp)
			{
				date.set_day(tmp);
				date.set_month(months);
				date.set_year(year);
				break;
			}
		}	
	}
	else
	{
		date.set_day(tmp);
		date.set_month(this->month);
		date.set_year(this->year);
	}
return date;
}

Date& Date::operator=(const Date& other)
{
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;

	return *this;
}

	

std::ostream& operator<< (std::ostream& output, Date const& date)
{
	if (date.day == 0 || date.month == 0)
		std::cout << " " << date.year;
	else if (date.day < 10 && date.month < 10)
		std::cout << " 0" << date.day << ".0" << date.month << "." << date.year;
	else if (date.day < 10)
		std::cout << " 0" << date.day << "." << date.month << "." << date.year;
	else if (date.month < 10)
		std::cout << " " << date.day << ".0" << date.month << "." << date.year;
	else
		std::cout << " " << date.day << "." << date.month << "." << date.year;

	return output;
}
