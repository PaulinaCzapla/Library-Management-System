#pragma once

#ifndef RESOURCE_H
#define RESOURCE_H

#include <iostream>
#include <string>
#include "Date.h"
#include "Text.h"


class Resource 
{
	friend std::ostream& operator<< (std::ostream&, Resource const&);
protected:
	std::string ID;
	std::string authors_name;
	std::string title;
	Date release_date;
	bool is_available;

public:
	Resource(std::string, std::string, Date, std::string ="brak", bool = true );
	Resource(std::string, Date, std::string = "brak", bool = true);
	Resource();
	void change_availability(bool);
	virtual void create_id(int)=0;
	bool operator==(const std::string&);
	std::string get_ID();
	std::string get_authors_name();
	std::string get_title();
	Date get_date();
	bool get_availability();
	virtual ~Resource();

};

#endif