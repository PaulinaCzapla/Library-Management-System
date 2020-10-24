#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "Borrowed.h" //date library list node


class Person
{
	friend std::ostream& operator<<(std::ostream& output, Person const& data);
	
	std::string name;
	Date birth_date;
	std::string address;
	std::string phone_number;

public:

std::string ID;
	List <Borrowed> borrowed_resources;

	Person(std::string, std::string, Date, std::string, std::string , List <Borrowed>);
	Person(std::string, std::string, Date, std::string, std::string);
	Person();
	std::string get_ID();
	std::string get_name();
	Date get_birth_date();
	std::string get_string_date();
	std::string get_address();
	std::string get_phone_number();
	bool operator==(const std::string&);

//operator =
};

#endif