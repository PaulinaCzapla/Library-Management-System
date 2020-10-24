#include "FileLibrary.h"

template<typename T>
FileLibrary<T>::FileLibrary<T>(std::string filename_) : File<T>(filename_) {}

template<typename T>
void FileLibrary<T>::read(Library& library)// ID imie nazwisko tytul data dostep
{
	Text text;
	std::fstream file;
	file.open(this->filename, std::ios::in);

	if (this->check(file))
	{
		std::string ID, name, surname, date, title;
		bool is_available;

		while (!file.eof())
		{
			if ((file >> ID >> name >> surname >> date >> is_available)) //sprawdzenie, czy dane siê prawid³owo wczytuj¹
			{
				getline(file, title);
				Date date_cl(date);
				switch (ID[0])
				{
				case 'K':
					Book book(ID, name + " " + surname, date_cl, title, is_available);
					Node<Book>* node = new Node<Book>(book);
					library.books.push_front(node);
					break;
				case 'C':
					CD cd(ID, name + " " + surname, date_cl, title, is_available);
					Node<CD>* node = new Node<CD>(cd);
					library.cds.push_front(node);

					break;
				case 'F':
					Movie movie(ID, name + " " + surname, date_cl, title, is_available);
					Node<Movie>* node = new Node<Movie>(movie);
					library.movies.push_front(node);
					break;
				default:
					continue;
				}
			}
			else
			{
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

template<typename T>
void FileLibrary<T>::write(Library& library) 
{

	Text text;
	std::fstream file;
	file.open(this->filename, std::ios::out);

	if (this->check(file))
	{
		Node<Book>* tmpB= library.books.get_head();
		Node<CD>* tmpC = library.cds.get_head();
		Node<Movie>* tmpM = library.movies.get_head();

		while (tmpB)
		{
			file << tmpB->get_current_data().get_ID();
			file << tmpB->get_current_data().get_authors_name();
			file << tmpB->get_current_data().get_date_string();
			file << tmpB->get_current_data().get_availability();
			file << tmpB->get_current_data().get_title();
			file << std::endl;

			tmpB = tmpB->get_next();
		}

		while (tmpC)
		{
			file << tmpC->get_current_data().get_ID();
			file << tmpC->get_current_data().get_authors_name();
			file << tmpC->get_current_data().get_date_string();
			file << tmpC->get_current_data().get_availability();
			file << tmpC->get_current_data().get_title();
			file << std::endl;

			tmpC = tmpC->get_next();
		}

		while (tmpM)
		{
			file << tmpM->get_current_data().get_ID();
			file << tmpM->get_current_data().get_authors_name();
			file << tmpM->get_current_data().get_date_string();
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