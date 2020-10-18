#include "Movie.h"

Movie::Movie(std::string id_, std::string name_, Date release_date_, Date borrow_date_, Date deadline_, std::string title_, bool is_available_, Person* borrower_)
	:Resource(id_, name_, release_date_, borrow_date_, deadline_, title_, is_available_, borrower_) {}

void Movie::create_id(int number)
{
	std::string M = "M";
	if (number < 10)
		this->ID = M + "00000" + std::to_string(number);
	else if (number < 100)
		this->ID = M + "0000" + std::to_string(number);
	else if (number < 1000)
		this->ID = M + "000" + std::to_string(number);
	else if (number < 10000)
		this->ID = M + "00" + std::to_string(number);
	else if (number < 100000)
		this->ID = M + "0" + std::to_string(number);
	else
		this->ID = M + std::to_string(number);
}