#include "LibraryActions.h"

void LibraryActions::borrow(Library& library, List<Person>& users)
{
	system("cls");
	std::cout << std::endl;

	std::string person_id, resource_id;
	bool is_founded = false, is_available = true;

	std::cout << "\n Podaj ID klienta: ";
	std::cin >> person_id;

	Node <Person>* person = users.get_element(person_id);

	if (person)
	{
		person->display();
		std::cout << "\n Podaj ID zasobu: ";
		std::cin >> resource_id;

		if (resource_id[0] == 'K')
		{
			Node<Book>* book = library.books.get_element(resource_id);
			if (book)
			{
				is_founded = true;
				book->display();
				if (book->get_current_data().get_availability())
					book->get_current_data().change_availability(false);
				else
					is_available = false;
			}
		}
		else if (resource_id[0] == 'C')
		{
			Node<CD>* cd = library.cds.get_element(resource_id);
			if (cd)
			{
				is_founded = true;
				cd->display();
				if (cd->get_current_data().get_availability())
					cd->get_current_data().change_availability(false);
				else
					is_available = false;
			}
		}
		else if (resource_id[0] == 'F')
		{
			Node<Movie>* movie = library.movies.get_element(resource_id);
			if (movie)
			{
				is_founded = true;
				movie->display();
				if (movie->get_current_data().get_availability())
					movie->get_current_data().change_availability(false);
				else
					is_available = false;
			}
		}
	}
	if (person == nullptr)
	{
		std::cout << std::endl;
		this->display_red(" Nie znaleziono takiej osoby. ");
		std::cout << std::endl;
	}
	else
		if (is_available)
		{
			if (is_founded)
			{
				Date today;
				Date deadline;
				deadline = today + BORROW_TIME;
				Borrowed borrowed(resource_id, today, deadline);
				Node <Borrowed>* nodeB = new Node <Borrowed>(borrowed);
				person->get_current_data().borrowed_resources.push_front(nodeB);
				std::cout << std::endl;
				this->display_green(" Wypozyczono ksiazke. ");
				std::cout << std::endl;
			}
			else
			{
				std::cout << std::endl;
				this->display_red(" Nie ma takiego zasobu.");
				std::cout << std::endl;
			}
		}
		else
		{
			std::cout << std::endl;
			this->display_red(" Zasob jest juz wypozyczony. ");
			std::cout << std::endl;
		}
	std::cout << std::endl;
	std::cout << "\n\n Wcisnij dowolny klawisz aby kontynuowac...";
	_getch();
}

void LibraryActions::make_a_return(Library& library, List<Person>& users)
{
	system("cls");
	std::cout << std::endl;

	std::string person_id, resource_id;
	char ch;

	std::cout << "\n Podaj ID klienta: ";
	std::cin >> person_id;

	Node <Person>* nodeP = users.get_element(person_id);

	if (nodeP)
	{
		nodeP->display();

		if (nodeP->get_current_data().borrowed_resources.get_head())
		{
			std::cout << std::endl;

			std::cout << "\n Podaj ID zasobu: ";
			std::cin >> resource_id;

			Node<Borrowed>* resource = nodeP->get_current_data().borrowed_resources.get_element(resource_id);
			if (resource)
			{
				int fine = resource->get_current_data().count_fine();

				if (fine > 0)
				{
					std::cout << "\n Opznienie w oddaniu: " << fine / PRICE << " dni.";
					std::cout << " Do zaplaty: " << fine << " zl." << std::endl;
					std::cout << "\n Wcisnij '1', aby potwierdzic orzymanie zaplaty. \n Wcisnij dowolny klawisz, aby anulowac zwrot. \n";
					std::cout << " >  ";
					std::cin >> ch;
					if (ch != '1')
						return;
				}
				else
				{
					std::cout << "\n Brak oplat do uiszczenia. " << std::endl;
				}

				nodeP->get_current_data().borrowed_resources.delete_element(resource);

				std::cout << std::endl;
				std::cout << std::endl;
				this->display_green(" Dokonano zwrotu. ");
				std::cout << std::endl;

				if (resource_id[0] == 'K')
				{
					Node<Book>* book = library.books.get_element(resource_id);
					if (!book)
					{
						std::cout << std::endl;
						this->display_red(" Nie znaleziono takiej ksiazki w bibliotece. ");
						std::cout << std::endl;
					}
					else
						book->get_current_data().change_availability(true);

				}
				else if (resource_id[0] == 'C')
				{
					Node<CD>* cd = library.cds.get_element(resource_id);
					if (!cd)
					{
						std::cout << std::endl;
						this->display_red(" Nie znaleziono takiej plyty u bibliotece. ");
						std::cout << std::endl;
					}
					else
						cd->get_current_data().change_availability(true);

				}
				else if (resource_id[0] == 'F')
				{
					Node<Movie>* movie = library.movies.get_element(resource_id);
					if (!movie)
					{
						std::cout << std::endl;
						this->display_red(" Nie znaleziono takiego filmu w bibliotece. ");
						std::cout << std::endl;
					}
					else
						movie->get_current_data().change_availability(true);
				}
				else
				{
					std::cout << std::endl;
					this->display_red(" Nie istnieje taki zasob. ");
					std::cout << std::endl;
				}
			}
			else
			{
				std::cout << std::endl;
				this->display_red(" Ta osoba nie wypozyczyla takiego zasobu. ");
				std::cout << std::endl;
			}
		}
		else
		{
			std::cout << std::endl;
			this->display_red(" Ta osoba nie ma wypozyczonych ksiazek. ");
			std::cout << std::endl;
		}
	}
	else
	{
		std::cout << std::endl;
		this->display_red(" Nie znaleziono takiej osoby. ");
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\n\n Wcisnij dowolny klawisz aby kontynuowac...";
	_getch();
}


bool LibraryActions::search_library_IDs(Library& library)
{
	system("cls");
	std::cout << std::endl;

	std::string resource_id;
	bool is_founded = false;

	std::cout << "\n Podaj ID zasobu: ";
	std::cin >> resource_id;

	if (resource_id[0] == 'K')
	{
		Node<Book>* book = this->find_book_byID(library.books, resource_id);
		if (book)
		{
			book->display();
			is_founded = true;
		}
	}
	else if (resource_id[0] == 'C')
	{
		Node<CD>* cd = this->find_cd_byID(library.cds, resource_id);
		if (cd)
		{
			cd->display();
			is_founded = true;
		}
	}
	else if (resource_id[0] == 'F')
	{
		Node<Movie>* movie = this->find_movie_byID(library.movies, resource_id);
		if (movie)
		{
			movie->display();
			is_founded = true;
		}
	}
	else
	{
		std::cout << std::endl;
		this->display_red(" Nie istnieje taki zasob. ");
		std::cout << std::endl;
	}
	return is_founded;
}

bool LibraryActions::search_library_titles(Library& library)
{
	std::cout << std::endl;
	char tmp;
	std::string title;
	bool is_founded = false;

	std::cout << "\n\n Podaj tytul zasobu: \n";
	std::cout << " >  ";

	getline(std::cin, title);

	Date tmpdate;
	Book tmp_book("", "", tmpdate, title, 0);
	CD tmp_cd("", "", tmpdate, title, 0);
	Movie tmp_movie("", "", tmpdate, title, 0);

	Node<Book>* book = this->find_book_byTitle(library.books, tmp_book);
	if (book)
	{
		book->display();
		is_founded = true;
	}

	if (!is_founded)
	{
		Node<CD>* cd = this->find_cd_byTitle(library.cds, tmp_cd);
		if (cd)
		{
			cd->display();
			is_founded = true;
		}
	}

	if (!is_founded)
	{
		Node<Movie>* movie = this->find_movie_byTitle(library.movies, tmp_movie);
		if (movie)
		{
			movie->display();
			is_founded = true;
		}
	}
	if (!is_founded)
	{
		std::cout << std::endl;
		this->display_red(" Nie istnieje taki zasob. ");
		std::cout << std::endl;
	}
	return is_founded;
}


void LibraryActions::show_imported_resources(Library& library, std::string& lib)
{
	std::string id_lib = "", id;
	Node<Book>* headB = library.books.get_head();
	Node<CD>* headC = library.cds.get_head();
	Node<Movie>* headM = library.movies.get_head();

	while (headB)
	{
		id = headB->get_current_data().get_ID();
		id_lib = "";
		id_lib += id[7];
		id_lib += id[8];
		id_lib += id[9];
		if (id_lib.compare(lib) != 0)
		{
			headB->display();
		}
		headB = headB->get_next();

	}
	while (headC)
	{
		id = headC->get_current_data().get_ID();
		id_lib = "";
		id_lib += id[7];
		id_lib += id[8];
		id_lib += id[9];

		if (id_lib.compare(lib) != 0)
		{
			headC->display();
		}
		headC = headC->get_next();
	}
	while (headM)
	{
		id = headM->get_current_data().get_ID();
		id_lib = "";
		id_lib += id[7];
		id_lib += id[8];
		id_lib += id[9];

		if (id_lib.compare(lib) != 0)
		{
			headM->display();
		}
		headM = headM->get_next();
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\n\n Wcisnij dowolny klawisz aby kontynuowac...";
	_getch();
}

void LibraryActions::import_resource(Library& library, Library& library2)
{
	std::string id;

	std::cout << "\n Podaj ID: ";
	std::cin >> id;
	char ch;
	bool is_done = false;

	if (id[0] == 'K')
	{
		Node<Book>* nodeB = this->find_book_byID(library2.books, id);
		if (nodeB)
		{
			nodeB->display();
			if (nodeB->get_current_data().get_availability() == true)
			{
				Node<Book>* book = new Node<Book>(nodeB->get_current_data());
				library.books.push_front(book);
				library2.books.delete_element(nodeB);

				std::cout << std::endl;
				this->display_green(" Dodano. ");
			}
			else
			{
				std::cout << std::endl;
				this->display_red(" Ksiazka jest aktualnie niedostepna. ");
				std::cout << std::endl;
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
			if (nodeC->get_current_data().get_availability() == true)
			{
				Node<CD>* cd = new Node<CD>(nodeC->get_current_data());
				library.cds.push_front(cd);
				library2.cds.delete_element(nodeC);

				std::cout << std::endl;
				this->display_green(" Dodano. ");
			}
			else
			{
				std::cout << std::endl;
				this->display_red(" Ksiazka jest aktualnie niedostepna. ");
				std::cout << std::endl;
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
			if (nodeM->get_current_data().get_availability() == true)
			{
				nodeM->display();
				Node<Movie>* movie = new Node<Movie>(nodeM->get_current_data());
				library.movies.push_front(movie);
				library2.movies.delete_element(nodeM);

				std::cout << std::endl;
				this->display_green(" Dodano. ");
			}
			else
			{
				std::cout << std::endl;
				this->display_red(" Ksiazka jest aktualnie niedostepna. ");
				std::cout << std::endl;
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

