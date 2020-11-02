#include "Menu.h"

void Menu::main_menu(Library& main_library, Library& library2, Library& library3, List<Person>& users)
{
	for (;;)
	{
		system("cls");
		std::cout << std::endl;
		std::cout << "\n                                           System biblioteczny\n\n";
		std::cout << "                                            [1] Wypozycz \n";
		std::cout << "                                            [2] Dodaj zwrot \n";
		std::cout << "                                            [3] Baza uzytkownikow \n";
		std::cout << "                                            [4] Zasoby biblioteki \n";
		std::cout << "                                            [5] Zasoby bibiotek zewnetrznych\n";
		std::cout << "                                            [0] Zapisz i wyjdz \n";
		std::cout << std::endl;

		char ch, tmp;

		for (;;)
		{
			std::cout << " >  ";
			std::cin >> ch;
			while ((tmp = getchar()) != '\n');

			if (ch == '0')
			{
				break;
			}

			switch (ch)
			{
			case '1':
				this->borrow(main_library, users);
				break;
			case '2':
				this->make_a_return(main_library, users);
				break;
			case '3':
				this->users_menu(users);
				break;
			case '4':
				this->resources_menu(main_library);
				break;
			case '5':
				this->external_libraries_menu(main_library, library2, library3);
				break;
			default:
				this->display_red(" Brak takiej opcji. \n");
				continue;
			}
			break;
		}
		if (ch == '0')
			break;
	}
}
void Menu::resources_menu(Library& library)
{
	for (;;)
	{
		system("cls");
		std::cout << std::endl;
		std::cout << "\n                                           Zasoby biblioteki\n\n";
		std::cout << "                                            [1] Wyswietl zasoby\n";
		std::cout << "                                            [2] Dodaj nowe zasoby \n";
		std::cout << "                                            [3] Usun zasob\n";
		std::cout << "                                            [0] Wyjdz \n";
		std::cout << std::endl;
		char ch, tmp;

		for (;;)
		{
			std::cout << " >  ";
			std::cin >> ch;
			while ((tmp = getchar()) != '\n');

			if (ch == '0')
				break;

			switch (ch)
			{
			case '1':
				this->display_library_menu(library);
				break;
			case '2':
				this->add_resource_menu(library);
				break;
			case '3':

				this->delete_resource(library);
				break;

			default:
			{
				this->display_red(" Brak takiej opcji. \n");
				continue;
			}
			}
			break;
		}
		if (ch == '0')
			break;
	}
}


void Menu::display_library_menu(Library& library)
{
	for (;;)
	{
		system("cls");
		std::cout << std::endl;
		std::cout << "\n                                            Wyswietl zasoby\n\n";
		std::cout << "                                            [1] Wyswietl wszystkie ksiazki \n";
		std::cout << "                                            [2] Wyswietl wszystkie plyty \n";
		std::cout << "                                            [3] Wyswietl wszystkie filmy \n";
		std::cout << "                                            [4] Wyswietl po ID \n";
		std::cout << "                                            [5] Wyswietl po tytule \n";
		std::cout << "                                            [0] Wyjdz \n";
		std::cout << std::endl;
		char ch, tmp;

		for (;;)
		{
			std::cout << " >  ";
			std::cin >> ch;
			while ((tmp = getchar()) != '\n');

			if (ch == '0')
				break;

			switch (ch)
			{
			case '1':
				library.books.display_list();
				std::cout << std::endl;
				std::cout << std::endl;
				std::cout << "\n\n Wcisnij dowolny klawisz aby kontynuowac...";
				_getch();
				break;
			case '2':
				library.cds.display_list();
				std::cout << std::endl;
				std::cout << std::endl;
				std::cout << "\n\n Wcisnij dowolny klawisz aby kontynuowac...";
				_getch();
				break;
			case '3':
				library.movies.display_list();
				std::cout << std::endl;
				std::cout << std::endl;
				std::cout << "\n\n Wcisnij dowolny klawisz aby kontynuowac...";
				_getch();
				break;
			case '4':
				this->search_library_IDs(library);
				std::cout << std::endl;
				std::cout << "\n\n Wcisnij dowolny klawisz aby kontynuowac...";
				_getch();
			case '5':
				this->search_library_titles(library);
				std::cout << std::endl;
				std::cout << "\n\n Wcisnij dowolny klawisz aby kontynuowac...";
				_getch();
				break;
			default:
			{
				this->display_red(" Brak takiej opcji. \n");
				continue;
			}
			}
			break;
		}
		if (ch == '0')
			break;
	}
}

void Menu::add_resource_menu(Library& library)
{
	for (;;)
	{
		system("cls");
		std::cout << std::endl;
		std::cout << "\n                                           Dodawanie zasobow\n\n";
		std::cout << "                                            [1] Dodaj ksiazke \n";
		std::cout << "                                            [2] Dodaj plyte \n";
		std::cout << "                                            [3] Dodaj film \n";
		std::cout << "                                            [0] Wyjdz \n";
		std::cout << std::endl;
		char ch, tmp;

		for (;;)
		{
			std::cout << " >  ";
			std::cin >> ch;
			while ((tmp = getchar()) != '\n');

			if (ch == '0')
				break;

			switch (ch)
			{
			case '1':
				this->add_new_book(library);
				break;
			case '2':
				this->add_new_cd(library);
				break;
			case '3':
				this->add_new_movie(library);
				break;

			default:
			{
				this->display_red(" Brak takiej opcji. \n");
				continue;
			}
			}
			break;
		}
		if (ch == '0')
			break;
	}
}

void Menu::external_libraries_menu(Library& library, Library& library2, Library& library3)
{
	for (;;)
	{
		system("cls");
		std::cout << std::endl;
		std::cout << "\n                                         Zasoby bibliotek zewnetrznych\n\n";
		std::cout << "                                            [1] Przeszukaj zasoby \n";
		std::cout << "                                            [2] Wyswietl zasoby bibliotek\n";
		std::cout << "                                            [3] Wyswietl sprowadzone zasoby \n";
		std::cout << "                                            [4] Sprowadz z biblioteki zewnetrznej\n";
		std::cout << "                                            [5] Zwroc/wypozycz bibliotece zewnetrznej\n";
		std::cout << "                                            [0] Wyjdz \n";
		std::cout << std::endl;

		std::string gl1 = "GL1";
		char ch, tmp;

		for (;;)
		{
			std::cout << " >  ";
			std::cin >> ch;
			while ((tmp = getchar()) != '\n');

			if (ch == '0')
				break;

			switch (ch)
			{
			case '1':
				this->libraries_menu(library, library2, library3, 1);
				break;
			case '2':
				this->libraries_menu(library, library2, library3, 2);
				break;
			case '3':
				this->show_imported_resources(library, gl1);
				break;
			case '4':
				this->libraries_menu(library, library2, library3, 3);
				break;
			case '5':
				this->libraries_menu(library, library2, library3, 4);
				break;

			default:
			{
				this->display_red(" Brak takiej opcji. \n");
				continue;
			}
			}
			break;
		}
		if (ch == '0')
			break;
	}
}

void Menu::users_menu(List<Person>& users)
{
	for (;;)
	{
		system("cls");
		std::cout << std::endl;
		std::cout << "\n                                              Uzytkownicy\n\n";
		std::cout << "                                            [1] Wyswietl wszystkich uzytkownikow \n";
		std::cout << "                                            [2] Znajdz uzytkownika po ID \n";
		std::cout << "                                            [3] Dodaj nowego uzytkownika \n";
		std::cout << "                                            [4] Usun uzytkownika \n";
		std::cout << "                                            [0] Wyjdz \n";
		std::cout << std::endl;

		char ch, tmp;

		for (;;)
		{
			std::cout << " >  ";
			std::cin >> ch;
			while ((tmp = getchar()) != '\n');

			if (ch == '0')
				break;

			switch (ch)
			{
			case '1':
				users.display_list();
				std::cout << std::endl;
				std::cout << std::endl;
				std::cout << "\n\n Wcisnij dowolny klawisz aby kontynuowac...";
				_getch();
				break;
			case '2':
				this->find_user_byID(users);
				std::cout << std::endl;
				std::cout << "\n\n Wcisnij dowolny klawisz aby kontynuowac...";
				_getch();
				break;
			case '3':
				this->add_new_user(users);
				break;

			case '4':
				this->delete_user(users);
				break;

			default:
			{
				this->display_red(" Brak takiej opcji. \n");
				continue;
			}
			}
			break;
		}
		if (ch == '0')
			break;
	}
}

void Menu::libraries_menu(Library& library, Library& library2, Library& library3, short int option)
{
	for (;;)
	{
		system("cls");
		std::cout << std::endl;
		std::cout << "\n                                         Dostepne biblioteki zewnetrzne\n\n";
		std::cout << "                                            [1] Biblioteka nr 2\n";
		std::cout << "                                            [2] Biblioteka nr 3 \n";
		std::cout << "                                            [0] Wyjdz \n";
		std::cout << std::endl;

		char ch, tmp;

		for (;;)
		{
			std::cout << " >  ";
			std::cin >> ch;
			while ((tmp = getchar()) != '\n');

			if (ch == '0')
				break;

			switch (ch)
			{
			case '1':
				if (option == 2)
					this->display_library_menu(library2);
				else if (option == 1)
				{
					this->search_library_IDs(library2);
					std::cout << std::endl;
					std::cout << "\n\n Wcisnij dowolny klawisz aby kontynuowac...";
					_getch();
				}
				else if (option == 3)
					this->import_resource(library, library2);
				else if (option == 4)
					this->import_resource(library2, library);
				break;
			case '2':
				if (option == 2)
					this->display_library_menu(library3);

				else if (option == 1)
				{
					this->search_library_IDs(library3);
					std::cout << std::endl;
					std::cout << "\n\n Wcisnij dowolny klawisz aby kontynuowac...";
					_getch();
				}
				else if (option == 3)
					this->import_resource(library, library3);
				else if (option == 4)
					this->import_resource(library3, library);
				break;

			default:
			{
				this->display_red(" Brak takiej opcji. \n");
				continue;
			}
			}
			break;
		}
		if (ch == '0')
			break;
	}
}