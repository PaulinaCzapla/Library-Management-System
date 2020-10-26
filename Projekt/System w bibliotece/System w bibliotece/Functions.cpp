#include "Functions.h"


void Functions::borrow(Library& library, List<Person>& users)
{
	system("cls");
	std::cout << std::endl;

	Text text;
	std::string person_id, resource_id;
	bool is_founded = false, is_available = true;

	std::cout << "\n Podaj ID klienta: ";
	std::cin >> person_id;

	Node <Person>* person = users.get_element(person_id);

	if (person)
	{
		std::cout << "\n Podaj ID zasobu: ";
		std::cin >> resource_id;


		if (resource_id[0] == 'K')
		{
			Node<Book>* book = library.books.get_element(resource_id);
	/*		if (!book)
			{
				std::cout << std::endl;
				text.display_red(" Nie znaleziono takiej ksiazki. ");
				std::cout << std::endl;
			}*/
			if(book)
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
	/*		if (!cd)
			{
				std::cout << std::endl;
				text.display_red(" Nie znaleziono takiej plyty. ");
				std::cout << std::endl;
			}*/
			if(cd)
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
		/*	if (!movie)
			{

				std::cout << std::endl;
				text.display_red(" Nie znaleziono takiego filmu. ");
				std::cout << std::endl;
			}*/
			if(movie)
			{
				is_founded = true;
				movie->display();
				if (movie->get_current_data().get_availability())
					movie->get_current_data().change_availability(false);
				else
					is_available = false;
			}
		}
	/*	else
		{
			std::cout << std::endl;
			text.display_red(" Nie istnieje taki zasob. ");
			std::cout << std::endl;
		}*/
	}
	if (person == nullptr)
	{
		std::cout << std::endl;
		text.display_red(" Nie znaleziono takiej osoby. ");
		std::cout << std::endl;
	}
	else
		if (is_available)
		{
			if (is_founded)
			{
				person->display();
				Date today;
				Date deadline;
				deadline = today + BORROW_TIME;
				Borrowed borrowed(resource_id, today, deadline);
				Node <Borrowed>* nodeB = new Node <Borrowed>(borrowed);
				person->get_current_data().borrowed_resources.push_front(nodeB);
				std::cout << std::endl;
				text.display_green(" Wypozyczono ksiazke. ");
				std::cout << std::endl;
			}
			else
			{
				std::cout << std::endl;
				text.display_red(" Nie ma takiego zasobu.");
				std::cout << std::endl;
			}
		}
		else
		{
			std::cout << std::endl;
			text.display_red(" Zasob jest juz wypozyczony. ");
			std::cout << std::endl;
		}

	std::cout << std::endl;
	std::cout << "\n\n Wcisnij dowolny klawisz aby kontynuowac...";
	_getch();
}

void Functions::make_a_return(Library& library, List<Person>& users)
{
	system("cls");
	std::cout << std::endl;

	Text text;
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
			nodeP->get_current_data().borrowed_resources.display_list();
			users.display_list();
			std::cout << std::endl;

			std::cout << "\n Podaj ID zasobu: ";
			std::cin >> resource_id;

			Node<Borrowed>* resource = nodeP->get_current_data().borrowed_resources.get_element(resource_id);
			if (resource)
			{
				int fine = resource->get_current_data().count_fine();

				if (fine > 0)
				{
					std::cout << "\n Opznienie w oddaniu: " << resource->get_current_data().get_deadline() - resource->get_current_data().get_borrow_date() << " dni.";
					std::cout << " Do zaplaty: " << fine << " zl." << std::endl;
					std::cout << "\n Wcisnij '1', aby potwierdzic orzymanie zaplaty. \n Wcisnij dowolny klawisz, aby anulowac zwrot. ";
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

				if (resource_id[0] == 'K')
				{
					Node<Book>* book = library.books.get_element(resource_id);
					if (!book)
					{
						std::cout << std::endl;
						text.display_red(" Nie znaleziono takiej ksiazki w bibliotece. ");
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
						text.display_red(" Nie znaleziono takiej plyty u bibliotece. ");
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
						text.display_red(" Nie znaleziono takiego filmu w bibliotece. ");
						std::cout << std::endl;
					}
					else
						movie->get_current_data().change_availability(true);
				}
				else
				{
					std::cout << std::endl;
					text.display_red(" Nie istnieje taki zasob. ");
					std::cout << std::endl;
				}
			}
			else
			{
				std::cout << std::endl;
				text.display_red(" Ta osoba nie wypozyczyla takiej ksiazki. ");
				std::cout << std::endl;
			}
		}
		else
		{
			std::cout << std::endl;
			text.display_red(" Ta osoba nie ma wypozyczonych ksiazek. ");
			std::cout << std::endl;
		}
	}
	else
	{
		std::cout << std::endl;
		text.display_red(" Nie znaleziono takiej osoby. ");
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "\n\n Wcisnij dowolny klawisz aby kontynuowac...";
	_getch();
}

Node <Person>* Functions::find_user_byID(List<Person>& users)
{
	//	system("cls");
	std::cout << std::endl;

	Text text;
	std::string person_id;
	char ch;

	std::cout << "\n Podaj ID klienta: ";
	std::cin >> person_id;

	Node <Person>* nodeP = users.get_element(person_id);

	if (nodeP)
	{
		std::cout << std::endl;
		nodeP->display();
	}
	else
	{
		text.display_red(" Nie ma takiej osoby.");
		std::cout << std::endl;
	}

	return nodeP;
}

void Functions::add_new_user(List<Person>& users)
{
	Text text;
	std::string person_id;
	char ch;
	Date date_cl;

	std::cout << "\n Podaj PESEL nowego uzytkownika: \n";
	std::cout << " >  ";
	std::cin >> person_id;

	Node <Person>* nodeP = users.get_element(person_id);

	if (!nodeP)
	{
		std::string name, surname, phone, address, date;

		std::cout << "\n Podaj imie: \n";
		std::cout << " >  ";
		std::cin >> name;
		std::cout << "\n Podaj nazwisko: \n";
		std::cout << " >  ";
		std::cin >> surname;
		std::cout << "\n Podaj date urodzenia w formacie dd-mm-rrrr lub dd.mm.rrrr: \n";
		for (;;)
		{
			std::cout << " >  ";
			std::cin >> date;
			if (date_cl.check_string(date))
				break;
			text.display_red(" Bledna data.");
			std::cout << std::endl;
		}
		date_cl.set_date_from_string(date);

		std::cout << "\n Podaj numer telefonu (9 cyfr): \n";

		bool number = true;
		for (;;)
		{
			std::cout << " >  ";
			std::cin >> phone;
			if (phone.length() == 9)
				for (int i = 0; i < phone.length(); i++)
				{
					if (!isdigit(phone[i]))
					{
						number = false;
						break;
					}
				}
			else
				number = false;

			if (!number)
			{
				text.display_red(" Bledny numer telefonu. ");
				std::cout << std::endl;
				number = true;
			}
			else
				break;
		}

		std::cout << "\n Podaj adres w formacie Miaso, Ulica numer: \n";
		std::cout << " >  ";
		char tmp;

		while ((tmp = getchar()) != '\n');
		getline(std::cin, address);


		Person person(person_id, name + " " + surname, date_cl, address, phone);
		Node<Person>* node = new Node<Person>(person);
		users.push_front(node);
		std::cout << std::endl;
		text.display_green(" Uzytkownik zostal dodany. ");
		std::cout << std::endl;
	}
	else
	{
		text.display_red(" Taki uzytkownik juz istnieje.");
		std::cout << std::endl;
	}
	std::cout << "\n\n Wcisnij dowolny klawisz aby kontynuowac...";
	_getch();
}

void Functions::delete_user(List<Person>& users)
{
	Text text;
	char ch;
	Node <Person>* node = this->find_user_byID(users);

	if (node)
	{
		std::cout << "\n Chcesz usunac uzytkownika? ";
		std::cout << "\n [1] Tak ";
		std::cout << "\n [2] Nie \n";
		for (;;)
		{
			std::cout << " >  ";
			std::cin >> ch;

			switch (ch)
			{
			case '1':
				users.delete_element(node);
				text.display_green(" Uzytkownik zostal usuniety. ");
				std::cout << std::endl;
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
	std::cout << "\n\n Wcisnij dowolny klawisz aby kontynuowac...";
	_getch();
}

void Functions::add_new_book(Library& library)
{
	std::string name, date, title;
	Text text;
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
			text.display_red(" Bledny rok. ");
			std::cout << std::endl;
			is_year = true;
			continue;
		}
		else
			break;
	}
	date = "01.01." + date;
	Date date_cl(date);

	Book book(library.books.size(), name, date_cl, title, true);
	Node<Book>* nodeb = new Node<Book>(book);
	library.books.push_front(nodeb);

	text.display_green(" Ksiazka zostala dodana. ");
	std::cout << std::endl;
	std::cout << "\n\n Wcisnij dowolny klawisz aby kontynuowac...";
	_getch();
}


void Functions::add_new_cd(Library& library)
{

	std::string name, date, title;
	Text text;
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
			text.display_red(" Bledny rok. ");
			std::cout << std::endl;
			is_year = true;
			continue;
		}
		else
			break;
	}

	date = "01.01." + date;
	Date date_cl(date);

	CD cd(library.cds.size(), name, date_cl, title, true);
	Node<CD>* nodecd = new Node<CD>(cd);
	library.cds.push_front(nodecd);

	text.display_green(" Plyta zostala dodana. ");
	std::cout << std::endl;
	std::cout << "\n\n Wcisnij dowolny klawisz aby kontynuowac...";
	_getch();

}

void Functions::add_new_movie(Library& library)
{
	std::string name, date, title;
	Text text;
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
			text.display_red(" Bledny rok. ");
			std::cout << std::endl;
			is_year = true;
			continue;
		}
		else
			break;
	}

	date = "01.01." + date;
	Date date_cl(date);

	Movie movie(library.movies.size(), name, date_cl, title, true);
	Node<Movie>* nodem = new Node<Movie>(movie);
	library.movies.push_front(nodem);

	text.display_green(" Ksiazka zostala dodana. ");
	std::cout << std::endl;
	std::cout << "\n\n Wcisnij dowolny klawisz aby kontynuowac...";
	_getch();

}

void Functions::delete_resource(Library& library)
{
	std::string id;

	Text text;
	std::cout << "\n Podaj ID: ";
	std::cin >> id;
	char ch;
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
					text.display_green(" Usunieto. ");
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
			text.display_red(" Brak zasobu o id ");
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
					text.display_green(" Usunieto. ");
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
			text.display_red(" Brak zasobu o id ");
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
					text.display_green(" Usunieto. ");
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
			text.display_red(" Brak zasobu o id ");
			std::cout << id << "." << std::endl;
		}
	}
	else
	{
		std::cout << std::endl;
		text.display_red(" Brak zasobu o id ");
		std::cout << id << "." << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\n\n Wcisnij dowolny klawisz aby kontynuowac...";
	_getch();
}

Node <Book>* Functions::find_book_byID(List<Book>& library, std::string id)
{
	Text text;

	Node<Book>* book = library.get_element(id);
	if (!book)
	{
		std::cout << std::endl;
		text.display_red(" Nie znaleziono takiej ksiazki w bibliotece. ");
		std::cout << std::endl;
	}
	return book;
}

Node <CD>* Functions::find_cd_byID(List<CD>& library, std::string id)
{
	Text text;

	Node<CD>* cd = library.get_element(id);
	if (!cd)
	{
		std::cout << std::endl;
		text.display_red(" Nie znaleziono takiej plyty w bibliotece. ");
		std::cout << std::endl;
	}
	return cd;
}

Node <Movie>* Functions::find_movie_byID(List<Movie>& library, std::string id)
{
	Text text;

	Node<Movie>* movie = library.get_element(id);
	if (!movie)
	{
		std::cout << std::endl;
		text.display_red(" Nie znaleziono takiej ksiazki w bibliotece. ");
		std::cout << std::endl;
	}
	return movie;
}

bool Functions::search_library(Library& library)
{
	system("cls");
	std::cout << std::endl;

	Text text;
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
		text.display_red(" Nie istnieje taki zasob. ");
		std::cout << std::endl;
	}
	return is_founded;
}

void Functions::show_imported_resources(Library& library, std::string& lib)
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

void Functions::import_resource(Library& library, Library& library2)
{
	std::string id;

	Text text;
	std::cout << "\n Podaj ID: ";
	std::cin >> id;
	char ch;

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
				text.display_green(" Dodano. ");
			}
			else
			{
				std::cout << std::endl;
				text.display_red(" Ksiazka jest aktualnie niedostepna. ");
				std::cout << std::endl;
			}
		}
		else
		{
			std::cout << std::endl;
			text.display_red(" Brak zasobu o id ");
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
				text.display_green(" Dodano. ");
			}
			else
			{
				std::cout << std::endl;
				text.display_red(" Ksiazka jest aktualnie niedostepna. ");
				std::cout << std::endl;
			}
		}
		else
		{
			std::cout << std::endl;
			text.display_red(" Brak zasobu o id ");
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
				text.display_green(" Dodano. ");
			}
			else
			{
				std::cout << std::endl;
				text.display_red(" Ksiazka jest aktualnie niedostepna. ");
				std::cout << std::endl;
			}
		}
		else
		{
			std::cout << std::endl;
			text.display_red(" Brak zasobu o id ");
			std::cout << id << "." << std::endl;
		}
	}
	else
	{
		std::cout << std::endl;
		text.display_red(" Brak zasobu o id ");
		std::cout << id << "." << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\n\n Wcisnij dowolny klawisz aby kontynuowac...";
	_getch();
}

