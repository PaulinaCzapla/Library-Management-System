#include "Resource.h"

Resource::Resource(std::string id_, std::string name_, Date release_date_, std::string title_, bool is_available_)
{
	this->ID = id_;
	this->authors_name = name_;
	this->release_date = release_date_;
	this->title = title_;
	this->is_available = is_available_;
}

Resource::Resource(std::string name_, Date release_date_, std::string title_, bool is_available_)
{
	this->ID = "brak";
	this->authors_name = name_;
	this->release_date = release_date_;
	this->title = title_;
	this->is_available = is_available_;
}

Resource::Resource()
{
	this->ID = "brak";
	this->authors_name = "brak";
	this->title = "brak";
	this->is_available = false;
	this->release_date;
}

void Resource::change_availability(bool is_available_)
{
	this->is_available = is_available_;
}

bool Resource::operator==(const std::string& id)
{
	if (id.compare(this->ID) == 0)
		return true;
	else
		return false;
}

bool Resource::operator==(const Resource& other)
{
	std::string tmp_t = this->title, tmp_o = other.title;

	for (char& c : tmp_t)
		c = tolower(c);

	for (char& c : tmp_o)
		c = tolower(c);

	if (tmp_t.compare(tmp_o) == 0)
		return true;
	else
		return false;
}

std::string Resource::get_ID()
{
	return this->ID;
}
std::string Resource::get_authors_name()
{
	return this->authors_name;
}
std::string Resource::get_title()
{
	return this->title;
}

std::string Resource::get_year_string()
{
	return this->release_date.year_to_string();
}
Date Resource::get_date()
{
	return this->release_date;
}
bool Resource::get_availability()
{
	return this->is_available;
}

std::ostream& operator<< (std::ostream& output, Resource& data)
{
	Text text;
	std::cout << " " << data.ID << "    " << data.authors_name << " | " << data.title << " | rok wydania:" << data.release_date.year_to_string() << " ";

	if (data.is_available)
	{
		text.display_green(" Dostepny. ");
		std::cout << std::endl << std::endl;
	}
	else
	{
		text.display_red(" Niedostepny. ");
		std::cout << std::endl << std::endl;
	}
	return output;
}


Resource::~Resource() {}

