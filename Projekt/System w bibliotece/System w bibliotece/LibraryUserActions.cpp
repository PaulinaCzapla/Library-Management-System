#include "LibraryUserActions.h"

Node <Person>* LibraryUserActions::find_user_byID(List<Person>& users)
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

void LibraryUserActions::add_new_user(List<Person>& users)
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

void LibraryUserActions::delete_user(List<Person>& users)
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