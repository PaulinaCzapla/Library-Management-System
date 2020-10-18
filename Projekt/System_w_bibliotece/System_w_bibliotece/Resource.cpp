#include "Resource.h"


Resource::Resource(std::string id_, std::string name_ , Date release_date_, Date borrow_date_, Date deadline_, std::string title_, bool is_available_, Person* borrower_)
{
	this->ID = id_;
	this->authors_name = name_;
	this->release_date = release_date_;
	this->borrow_date = borrow_date_;
	this->deadline = deadline_;
	this->title = title_;
	this->is_available = is_available_;
	this->borrower = borrower_;
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

Resource& Resource::operator=(const Resource& other)
{
	this->authors_name = other.authors_name;
	this->borrow_date = other.borrow_date;
	this->deadline = other.deadline;
	this->ID = other.ID;
	this->is_available = other.is_available;
	this->release_date = other.release_date;
	this->title = other.title;

	return *this;
}

std::ostream& Resource::operator<< (std::ostream& output)
{
	Text text;
	std::cout << " " << this->ID << " " << this->title << " " << this->authors_name << " rok wydania:" << this->release_date << " ";

	if (this->is_available)
	{
		text.display_green(" Dostepny. ");
		std::cout << std::endl << std::endl;
	}
		
	else
	{
		text.display_red(" Niedostepny. ");
		std::cout << std::endl;
		std::cout << " " << this->borrower << " " << this->borrow_date << " " << this->deadline << std::endl;
		std::cout << std::endl << std::endl;
	
	}
}