#include "CD.h"

CD::CD(std::string id_, std::string name_, Date release_date_, Date borrow_date_, Date deadline_, std::string title_, bool is_available_, Person* borrower_)
	:Resource(id_, name_, release_date_, borrow_date_, deadline_, title_, is_available_, borrower_) {}

void CD::create_id(int number)
{
	std::string c = "C";
	if (number < 10)
		this->ID = c + "00000" + std::to_string(number);
	else if (number < 100)
		this->ID = c + "0000" + std::to_string(number);
	else if (number < 1000)
		this->ID = c + "000" + std::to_string(number);
	else if (number < 10000)
		this->ID = c + "00" + std::to_string(number);
	else if (number < 100000)
		this->ID = c + "0" + std::to_string(number);
	else
		this->ID = c + std::to_string(number);
}