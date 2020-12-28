#include "Person.h"

Person::Person(std::string id_, std::string name_, Date date_, std::string address_, std::string phone_, List <Borrowed> list_)
{
	this->ID = id_;
	this->name = name;
	this->birth_date = date_;
	this->address = address_;
	this->phone_number = phone_;
	this->borrowed_resources = list_;
}

Person::Person(std::string id_, std::string name_, Date date_, std::string address_, std::string phone_)
{
	this->ID = id_;
	this->name = name_;
	this->birth_date = date_;
	this->address = address_;
	this->phone_number = phone_;
	this->borrowed_resources;
}

Person::Person()
{
	this->address = "brak";
	this->birth_date;
	this->borrowed_resources;
	this->ID = "brak";
	this->phone_number = "brak";
}

std::string Person::get_ID()
{
	return this->ID;
}
std::string Person::get_name()
{
	return this->name;
}
Date Person::get_birth_date()
{
	return this->birth_date;
}
std::string Person::get_string_date()
{
	return this->birth_date.date_to_string();
}
std::string Person::get_address()
{
	return this->address;
}
std::string Person::get_phone_number()
{
	return this->phone_number;
}

bool Person::operator==(const std::string& id)
{
	if (id.compare(this->ID) == 0)
		return true;
	else
		return false;
}

std::ostream& operator<< (std::ostream& output, Person& data)
{
	printf("\n ID %-10s  |  %-23s  |  %-10s  |  tel. %-9s  |  %-s", data.ID.c_str(), data.name.c_str(), data.birth_date.date_to_string().c_str(), data.phone_number.c_str(), data.address.c_str());
	data.borrowed_resources.display_list();
	std::cout << std::endl;
	return output;
}