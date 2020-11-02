#include "ResourcesActions.h"


void ResourcesActions::add_new_book(Library& library)
{
	std::string name, date, title;
	char tmp;

	std::cout << "\n Podaj imie i nazwisko autora: \n";
	std::cout << " >  ";

	getline(std::cin, name);

	std::cout << "\n Podaj tytul ksiazki: \n";
	std::cout << " >  ";
	getline(std::cin, title);

	std::cout << "\n Podaj rok wydania: \n";

	bool is_year = true;

	for (;;)
	{
		std::cout << " >  ";
		std::cin >> date;

		if (date.length() == 4)
			for (int i = 0; i < date.length(); i++)
			{
				if (!isdigit(date[i]))
				{
					is_year = false;
					break;
				}
			}
		else
			is_year = false;
		if (!is_year)
		{
			this->display_red(" Bledny rok. ");
			std::cout << std::endl;
			is_year = true;
			continue;
		}
		else
			break;
	}
	date = "01.01." + date;
	Date date_cl(date);

	Book book(library.books.size() +1 , name, date_cl, title, true);
	Node<Book>* nodeb = new Node<Book>(book);
	library.books.push_front(nodeb);

	this->display_green(" Ksiazka zostala dodana. ");
	std::cout << std::endl;
	std::cout << "\n\n Wcisnij dowolny klawisz aby kontynuowac...";
	_getch();
}

void ResourcesActions::add_new_cd(Library& library)
{
	std::string name, date, title;
	char tmp;
	std::cout << "\n Podaj imie i nazwisko tworcy/nazwe zespolu: \n";
	std::cout << " >  ";
	getline(std::cin, name);

	std::cout << "\n Podaj tytul plyty: \n";
	std::cout << " >  ";
	getline(std::cin, title);

	std::cout << "\n Podaj rok wydania: \n";
	bool is_year = true;

	for (;;)
	{
		std::cout << " >  ";
		std::cin >> date;

		if (date.length() == 4)
			for (int i = 0; i < date.length(); i++)
			{
				if (!isdigit(date[i]))
				{
					is_year = false;
					break;
				}
			}
		else
			is_year = false;
		if (!is_year)
		{
			this->display_red(" Bledny rok. ");
			std::cout << std::endl;
			is_year = true;
			continue;
		}
		else
			break;
	}

	date = "01.01." + date;
	Date date_cl(date);

	CD cd(library.cds.size() + 1, name, date_cl, title, true);
	Node<CD>* nodecd = new Node<CD>(cd);
	library.cds.push_front(nodecd);

	this->display_green(" Plyta zostala dodana. ");
	std::cout << std::endl;
	std::cout << "\n\n Wcisnij dowolny klawisz aby kontynuowac...";
	_getch();
}

void ResourcesActions::add_new_movie(Library& library)
{
	std::string name, date, title;
	char tmp;

	std::cout << "\n Podaj imie i nazwisko rezysera: \n";
	std::cout << " >  ";
	getline(std::cin, name);

	std::cout << "\n Podaj tytul filmu: \n";
	std::cout << " >  ";
	getline(std::cin, title);

	std::cout << "\n Podaj rok wydania: \n";

	bool is_year = true;

	for (;;)
	{
		std::cout << " >  ";
		std::cin >> date;

		if (date.length() == 4)
			for (int i = 0; i < date.length(); i++)
			{
				if (!isdigit(date[i]))
				{
					is_year = false;
					break;
				}
			}
		else
			is_year = false;
		if (!is_year)
		{
			this->display_red(" Bledny rok. ");
			std::cout << std::endl;
			is_year = true;
			continue;
		}
		else
			break;
	}

	date = "01.01." + date;
	Date date_cl(date);

	Movie movie(library.movies.size() + 1, name, date_cl, title, true);
	Node<Movie>* nodem = new Node<Movie>(movie);
	library.movies.push_front(nodem);

	this->display_green(" Ksiazka zostala dodana. ");
	std::cout << std::endl;
	std::cout << "\n\n Wcisnij dowolny klawisz aby kontynuowac...";
	_getch();
}

void ResourcesActions::delete_resource(Library& library)
{
	std::string id;
	char ch;

	std::cout << "\n Podaj ID: \n >";
	std::cin >> id;

	if (id[0] == 'K')
	{
		Node<Book>* nodeB = this->find_book_byID(library.books, id);
		if (nodeB)
		{
			nodeB->display();
			std::cout << "\n Chcesz usunac ksiazke? ";
			std::cout << "\n [1] Tak ";
			std::cout << "\n [2] Nie \n";
			for (;;)
			{
				std::cout << " >  ";
				std::cin >> ch;

				switch (ch)
				{
				case '1':
					library.books.delete_element(nodeB);
					std::cout << std::endl;
					this->display_green(" Usunieto. ");
					std::cout << std::endl;
					break;
				case '2':
					break;
				default:
					continue;
				}
				break;
			}
		}
		else
		{
			std::cout << std::endl;
			this->display_red(" Brak zasobu o id ");
			std::cout << id << "." << std::endl;
		}
	}
	else if (id[0] == 'C')
	{
		Node<CD>* nodeC = this->find_cd_byID(library.cds, id);
		if (nodeC)
		{
			nodeC->display();
			std::cout << std::endl;
			std::cout << "\n Chcesz usunac plyte? ";
			std::cout << "\n [1] Tak ";
			std::cout << "\n [2] Nie \n";
			for (;;)
			{
				std::cout << " >  ";
				std::cin >> ch;

				switch (ch)
				{
				case '1':
					library.cds.delete_element(nodeC);
					std::cout << std::endl;
					this->display_green(" Usunieto. ");
					std::cout << std::endl;
					break;
				case '2':
					break;
				default:
					continue;
				}
				break;
			}
		}
		else
		{
			std::cout << std::endl;
			this->display_red(" Brak zasobu o id ");
			std::cout << id << "." << std::endl;
		}
	}
	else if (id[0] == 'F')
	{
		Node<Movie>* nodeM = this->find_movie_byID(library.movies, id);
		if (nodeM)
		{
			nodeM->display();
			std::cout << std::endl;
			std::cout << "\n Chcesz usunac film? ";
			std::cout << "\n [1] Tak ";
			std::cout << "\n [2] Nie \n";
			for (;;)
			{
				std::cout << " >  ";
				std::cin >> ch;

				switch (ch)
				{
				case '1':
					library.movies.delete_element(nodeM);
					std::cout << std::endl;
					this->display_green(" Usunieto. ");
					std::cout << std::endl;
					break;
				case '2':
					break;
				default:
					continue;
				}
				break;
			}
		}
		else
		{
			std::cout << std::endl;
			this->display_red(" Brak zasobu o id ");
			std::cout << id << "." << std::endl;
		}
	}
	else
	{
		std::cout << std::endl;
		this->display_red(" Brak zasobu o id ");
		std::cout << id << "." << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\n\n Wcisnij dowolny klawisz aby kontynuowac...";
	_getch();
}

Node <Book>* ResourcesActions::find_book_byID(List<Book>& library, std::string id)
{
	Node<Book>* book = library.get_element(id);
	if (!book)
	{
		std::cout << std::endl;
		this->display_red(" Nie znaleziono takiej ksiazki w bibliotece. ");
		std::cout << std::endl;
	}
	return book;
}

Node <CD>* ResourcesActions::find_cd_byID(List<CD>& library, std::string id)
{
	Node<CD>* cd = library.get_element(id);
	if (!cd)
	{
		std::cout << std::endl;
		this->display_red(" Nie znaleziono takiej plyty w bibliotece. ");
		std::cout << std::endl;
	}
	return cd;
}

Node <Movie>* ResourcesActions::find_movie_byID(List<Movie>& library, std::string id)
{
	Node<Movie>* movie = library.get_element(id);
	if (!movie)
	{
		std::cout << std::endl;
		this->display_red(" Nie znaleziono takiej ksiazki w bibliotece. ");
		std::cout << std::endl;
	}
	return movie;
}


Node <Book>* ResourcesActions::find_book_byTitle(List<Book>& library, Book& book)
{
	Node<Book>* nbook = library.get_element(book);
	return nbook;
}

Node <CD>* ResourcesActions::find_cd_byTitle(List<CD>& library, CD& cd)
{
	Node<CD>* ncd = library.get_element(cd);
	return ncd;
}

Node <Movie>* ResourcesActions::find_movie_byTitle(List<Movie>& library, Movie& movie)
{
	Node<Movie>* nmovie = library.get_element(movie);
	return nmovie;
}