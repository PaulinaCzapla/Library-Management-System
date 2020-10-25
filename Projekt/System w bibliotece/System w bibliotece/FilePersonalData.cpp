#include "FilePersonalData.h"




FilePersonalData::FilePersonalData(std::string filename_) : File<List<Person>>(filename_) {}


void FilePersonalData::read(List<Person>& users)// 55082998585 Anastazja Wlodarczyk 1955-08-29 414508198 Chorzow, Kujawska 5
{
	Text text;
	std::fstream file;
	file.open(this->filename, std::ios::in);

	if (this->check(file))
	{
		std::string ID, name,  date, phone, address, tmp;
		int i = 0;
		bool digit;

		while (!file.eof())
		{
			if (file >> ID >> name)
			{
				digit = false;
				tmp = name;
				for (int j = 0; ; j++)
				{
					file >> tmp;
					for (char ch : tmp)
						if (isdigit(ch))
						{
							digit = true;
							date = tmp;
							break;
						}

					if (digit)
						break;

					name = name + " " + tmp;
				}

				file >> phone;

				i++;
				getline(file, address);
				Date date_cl(date);

				Person person(ID, name, date_cl, address, phone);
				Node<Person>* node = new Node<Person>(person);
				users.push_front(node);
			}
			else
			{
				if (i == 0)
					break;
				text.display_red(" Blad. Nieprawidlowy format pliku ");
				std::cout << this->filename << std::endl;
				break;
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

void FilePersonalData::write(List<Person>& users)
{
	Text text;
	std::fstream file;
	file.open(this->filename, std::ios::out);

	auto personHead = users.get_head();


	if (this->check(file)) // 55082998585 Anastazja Wlodarczyk 1955-08-29 414508198 Chorzow, Kujawska 5
	{
		while (personHead)
		{
			file << personHead->get_current_data().get_ID() << " ";
			file << personHead->get_current_data().get_name() << " ";
			file << personHead->get_current_data().get_string_date() << " ";
			file << personHead->get_current_data().get_phone_number() << " ";
			file << personHead->get_current_data().get_address();
			file << std::endl;

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