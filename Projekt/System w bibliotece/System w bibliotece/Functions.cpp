#include "Functions.h"


void Functions::borrow(Library* libraries, List<Person>& users)
{
	system("cls");
	std::cout << std::endl;

	Text text;
	std::string person_id, resource_id;
	bool is_founded = false;

	std::cout << "\n Podaj ID zasobu: ";
	std::cin >> resource_id;


	if (resource_id[0] == 'K')
	{
		Node<Book>* book = libraries[0].books.get_element(resource_id);
		if (!book)
		{
			std::cout << std::endl;
			text.display_red(" Nie znaleziono takiej ksiazki. ");
			std::cout << std::endl;
		}
		else
		{
			book->display();
			is_founded = true;
		}
	}
	else if (resource_id[0] == 'C')
	{
		Node<CD>* cd = libraries[0].cds.get_element(resource_id);
		if (!cd)
		{
			std::cout << std::endl;
			text.display_red(" Nie znaleziono takiej plyty. ");
			std::cout << std::endl;
		}
		else
		{
			cd->display();
			is_founded = true;
		}
	}
	else if (resource_id[0] == 'F')
	{
		Node<Movie>* movie = libraries[0].movies.get_element(resource_id);
		if (!movie)
		{

			std::cout << std::endl;
			text.display_red(" Nie znaleziono takiego filmu. ");
			std::cout << std::endl;
		}
		else
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

	if (is_founded)
	{
		std::cout << "\n Podaj ID klienta: ";
		std::cin >> person_id;

		Node <Person>* person = users.get_element(person_id);

		if (person)
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
			text.display_red(" Nie znaleziono takiej osoby. ");
			std::cout << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << "\n\n Wcisnij dowolny klawisz aby kontynuowac...";
	_getch();

}


void Functions::make_a_return(Library* libraries, List<Person>& users)
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
					Node<Book>* book = libraries[0].books.get_element(resource_id);
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
					Node<CD>* cd = libraries[0].cds.get_element(resource_id);
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
					Node<Movie>* movie = libraries[0].movies.get_element(resource_id);
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
		std::cout<<"\n Chcesz usunac uzytkownika? ";
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