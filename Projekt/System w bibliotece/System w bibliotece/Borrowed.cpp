#include "Borrowed.h"


Borrowed::Borrowed(std::string resource_ID, Date borrow_date_, Date deadline_)
{
	this->resource_ID = resource_ID;
	this->borrow_date = borrow_date_;
	this->deadline = deadline_;
}


Borrowed::Borrowed()
{
	this->resource_ID = "nieznany";
	this->borrow_date;
	this->deadline;
}


void Borrowed::display(Library* libraries)
{
	Text text;
	switch (this->resource_ID[0])
	{
	case 'K':
		for (int i = 0; i < LIBRARIES_NUM; i++)
		{
			auto element = libraries[0].books.get_element(this->resource_ID);
			if (element)
			{
				std::cout << "Typ: ksiazka " << element->get_current_data().get_ID() << " " << element->get_current_data().get_authors_name() << " \"" << element->get_current_data().get_title() << "\" " << element->get_current_data().get_year_string() << std::endl;
				std::cout << " wypozyczono: " << this->borrow_date << " termin oddania: " << this->deadline;
				break;
			}
		}
		
		break;
	case 'C':
		for (int i = 0; i < LIBRARIES_NUM; i++)
		{
			auto element = libraries[0].cds.get_element(this->resource_ID);
			if (element)
			{
				std::cout << "Typ: plyta CD " << element->get_current_data().get_ID() << " " << element->get_current_data().get_authors_name() << " \"" << element->get_current_data().get_title() << "\" " << element->get_current_data().get_year_string() << std::endl;
				std::cout << " wypozyczono: " << this->borrow_date << " termin oddania: " << this->deadline;
				break;
			}
		}

		break;
	case 'F':
		for (int i = 0; i < LIBRARIES_NUM; i++)
		{
			auto element = libraries[0].movies.get_element(this->resource_ID);
			if (element)
			{
				std::cout << "Typ: film " << element->get_current_data().get_ID() << " " << element->get_current_data().get_authors_name() << " \"" << element->get_current_data().get_title() << "\" " << element->get_current_data().get_year_string() << std::endl;
				std::cout << " wypozyczono: " << this->borrow_date << " termin oddania: " << this->deadline;
				break;
			}
		}

		break;
	default:
		text.display_red(" Brak zasobu. ");
		std::cout << std::endl;
		break;
	}
}



std::string Borrowed::get_resource_ID()
{
	return this->resource_ID;
}

Date Borrowed::get_borrow_date()
{
	return this->borrow_date;
}

Date Borrowed::get_deadline()
{
	return this->deadline;
}

int Borrowed::count_fine()
{
	int diff = this->deadline - this->borrow_date;

	if (diff < 0)
		return (diff * PRICE);
	else
		return 0;
}

bool Borrowed::operator==(const std::string& id)
{
	if (id.compare(this->resource_ID) == 0)
		return true;
	else
		return false;
}