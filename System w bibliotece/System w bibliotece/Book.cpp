#include "Book.h"

Book::Book(std::string id_, std::string name_, Date release_date_, std::string title_, bool is_available_)
	:Resource(id_, name_, release_date_, title_, is_available_ ){}

Book::Book(int num_, std::string name_, Date release_date_, std::string title_, bool is_available_)
	: Resource(name_, release_date_, title_, is_available_)
{
	this->create_id(num_);
}

Book::Book() : Resource() {}

void Book::create_id(int number)
{
	std::string k = "K";
	if (number < 10)
		this->ID = k + "00000" + std::to_string(number);
	else if (number < 100)
		this->ID = k + "0000" + std::to_string(number);
	else if (number < 1000)
		this->ID = k + "000" + std::to_string(number);
	else if (number < 10000)
		this->ID = k + "00" + std::to_string(number);
	else if (number < 100000)
		this->ID = k + "0" + std::to_string(number);
	else
		this->ID = k + std::to_string(number);

	this->ID += "GL1";
}

Book& Book::operator=(const Book& other)
{
	this->authors_name = other.authors_name;
	this->ID = other.ID;
	this->is_available = other.is_available;
	this->release_date = other.release_date;
	this->title = other.title;

	return *this;
}

Book::~Book() {}