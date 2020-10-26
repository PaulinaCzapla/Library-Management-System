#include "FileLibrary.h"


FileLibrary::FileLibrary(std::string filename_) : File(filename_) {}


void FileLibrary::read(Library& library)// ID imie nazwisko tytul data dostep
{
	Text text;
	std::fstream file;
	file.open(this->filename, std::ios::in);

	if (this->check(file))
	{
		std::string ID, name, surname, date, title, tmp, tmp2 = "";
		bool is_available, digit;
		int i = 0;
		while (!file.eof())
		{
			if (file >> ID >> name)
			{
				i++;
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
				file >> is_available;
				getline(file, title);

				date = "01.01." + date;
				Date date_cl(date);

				tmp2 = "";
				tmp2 += ID[7];
				tmp2 += ID[8];
				tmp2 += ID[9];

				if (ID[0] == 'K')
				{
					Book book(ID, name, date_cl, title, is_available);
					Node<Book>* nodeb = new Node<Book>(book);
					library.books.push_front(nodeb);

					if (tmp2.compare("GL1") != 0)
						library.books.decrease_counter();
				}
				else if (ID[0] == 'C')
				{
					CD cd(ID, name, date_cl, title, is_available);
					Node<CD>* nodec = new Node<CD>(cd);
					library.cds.push_front(nodec);

					if (tmp2.compare("GL1") != 0)
						library.cds.decrease_counter();
				}
				else if (ID[0] == 'F')
				{
					Movie movie(ID, name, date_cl, title, is_available);
					Node<Movie>* nodem = new Node<Movie>(movie);
					library.movies.push_front(nodem);

					if (tmp2.compare("GL1") != 0)
						library.movies.decrease_counter();
				}
				else
					continue;
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


void FileLibrary::write(Library& library)
{

	Text text;
	std::fstream file;
	file.open(this->filename, std::ios::out);

	if (this->check(file))
	{
		Node<Book>* tmpB = library.books.get_head();
		Node<CD>* tmpC = library.cds.get_head();
		Node<Movie>* tmpM = library.movies.get_head();

		while (tmpB)
		{
			file << tmpB->get_current_data().get_ID() << " ";
			file << tmpB->get_current_data().get_authors_name() << " ";
			file << tmpB->get_current_data().get_year_string() << " ";
			file << tmpB->get_current_data().get_availability() << " ";
			file << tmpB->get_current_data().get_title() << " ";
			file << std::endl;

			tmpB = tmpB->get_next();
		}

		while (tmpC)
		{
			file << tmpC->get_current_data().get_ID();
			file << tmpC->get_current_data().get_authors_name();
			file << tmpC->get_current_data().get_year_string();
			file << tmpC->get_current_data().get_availability();
			file << tmpC->get_current_data().get_title();
			file << std::endl;

			tmpC = tmpC->get_next();
		}

		while (tmpM)
		{
			file << tmpM->get_current_data().get_ID();
			file << tmpM->get_current_data().get_authors_name();
			file << tmpM->get_current_data().get_year_string();
			file << tmpM->get_current_data().get_availability();
			file << tmpM->get_current_data().get_title();
			file << std::endl;

			tmpM = tmpM->get_next();
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