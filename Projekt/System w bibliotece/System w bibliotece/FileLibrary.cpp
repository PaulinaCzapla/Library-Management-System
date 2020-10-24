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

		while (!plik.eof())
		{
			if ((plik >> ID >> name >> surname >> date >> is_available)) //sprawdzenie, czy dane siê prawid³owo wczytuj¹
			{
				getline(plik, title);
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
			}
		}
	}
	else
	{
		text.display_red(" Nie udalo sie otworzyc pliku ");
		std::cout << this->filename << std::endl;
	}
}

template<typename T>
void FileLibrary<T>::write(Library& library) 
{

	Text text;
	std::fstream file;
	file.open(this->filename, std::ios::out);

	Node<Book>* bookHead = library.books.get_head();
	Node<CD>* cdHead = library.cds.get_head();
	Node<Movie>* movieHead = library.movies.get_head();


	if (this->check(file))
	{
		Node<Book>* tmpB(bookHead);
		Node<CD>* tmpC(cdHead);
		Node<Movie>* tmpM(movieHead);

		while (tmpB)
		{
			plik << tmpB->get_current().get_ID();
			plik << tmpB->get_current().get_authors_name();
			plik << tmpB->get_current().get_date();
			plik << tmpB->get_current().get_availability();
			plik << tmpB->get_current().get_title();
			plik << std::endl;

			tmpB = tmpB->get_next();
		}

		while (tmpC)
		{
			plik << tmpC->get_current().get_ID();
			plik << tmpC->get_current().get_authors_name();
			plik << tmpC->get_current().get_date();
			plik << tmpC->get_current().get_availability();
			plik << tmpC->get_current().get_title();
			plik << std::endl;

			tmpC = tmpC->get_next();
		}

		while (tmpM)
		{
			plik << tmpM->get_current().get_ID();
			plik << tmpM->get_current().get_authors_name();
			plik << tmpM->get_current().get_date();
			plik << tmpM->get_current().get_availability();
			plik << tmpM->get_current().get_title();
			plik << std::endl;

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
}