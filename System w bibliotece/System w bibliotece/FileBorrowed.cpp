#include "FileBorrowed.h"

FileBorrowed::FileBorrowed(std::string filename_) : File<List<Person>>(filename_) {}

void FileBorrowed::read(List<Person>& users)
{ 
	Text text;
	std::fstream file;
	file.open(this->filename, std::ios::in);
	int i = 0;

	if (this->check(file))
	{
		std::string personID, resourceID, borrow_date, deadline;

		while (!file.eof())
		{
			if (file >> personID >> resourceID >> borrow_date >> deadline)
			{
				i++;
				Date date_cl(borrow_date);
				Date deadline_cl(deadline);

				auto person = users.get_element(personID);

				if (person)
				{
					Borrowed borrowed(resourceID, date_cl, deadline_cl);
					Node<Borrowed>* node = new Node<Borrowed>(borrowed);
					person->get_current_data().borrowed_resources.push_front(node);
				}
			}
			else
			{
				if (i == 0)
				{
					text.display_red(" Blad. Nieprawidlowy format pliku ");
					std::cout << this->filename << std::endl;
					break;
				}
			}
		}
	}
	else
	{
		text.display_red(" Nie udalo sie otworzyc pliku ");
		std::cout << this->filename << std::endl;
	}
	file.close();
}


void FileBorrowed::write(List<Person>& users)
{
	Text text;
	std::fstream file;
	file.open(this->filename, std::ios::out);

	auto personHead = users.get_head();

	if (this->check(file)) 
	{
		while (personHead)
		{
			auto borrowedHead = personHead->get_current_data().borrowed_resources.get_head();

			while (borrowedHead)
			{
				file << personHead->get_current_data().get_ID() << " ";
				file << borrowedHead->get_current_data().get_resource_ID() << " ";
				file << borrowedHead->get_current_data().get_borrow_date().date_to_string() << " ";
				file << borrowedHead->get_current_data().get_deadline().date_to_string();
				file << std::endl;
				borrowedHead = borrowedHead->get_next();
			}
			personHead = personHead->get_next();
		}
		text.display_green(" Zapisano. ");
		std::cout << std::endl;
	}
	else
	{
		text.display_red(" Nie udalo sie otworzyc pliku ");
		std::cout << this->filename << std::endl;
	}
	file.close();
}
