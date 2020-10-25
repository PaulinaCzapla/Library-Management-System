#include "Menu.h"

void Menu::main_menu(Library* libraries, List<Person>& users)
{
	for (;;)
	{
		system("cls");
		printf("\n");
		printf("\n                                           System biblioteczny\n\n");
		printf("                                            [1] Wypozycz \n");
		printf("                                            [2] Dodaj zwrot \n");
		printf("                                            [3] Baza uzytkownikow \n");
		printf("                                            [4] Zasoby biblioteki \n");
		printf("                                            [5] Zasoby bibiotek zewnetrznych\n");
		printf("                                            [6] Zapisz zmiany \n");
		printf("                                            [0] Zamknij program \n");
		printf("\n");

		char ch, tmp;
		Functions function;

		for(;;)
		{
			std::cout<<" >  ";
			std::cin >> ch;

			if (ch == '0')
			{
				break;
			}
				

			switch (ch)
			{
			case '1':
				function.borrow(libraries, users);
				break;
			case '2':
				function.make_a_return(libraries, users);
				break;
			case '3':
				this->users_menu(users);
				break;
			case '4':
	
				break;
			case '5':

				break;
			case '6':
	
				break;
			default:
				//alert
				continue;
			}
			break;
		}
		if (ch == '0')
			break;

	}
}
void Menu::resources_menu()
{
	for (;;)
	{
		system("cls");
		printf("\n");
		printf("\n                                           Zasoby biblioteki\n\n");
		printf("                                            [1] Wyswietl \n");
		printf("                                            [2] Dodaj nowe zasoby \n");
		printf("                                            [3] Usun zasob\n");
		printf("                                            [0] Wyjdz \n");
		printf("\n");
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
			
				break;
			case '2':
		
				break;
			case '3':
			

				break;
		
			default:
			{
				//alert
				continue;
			}
			}
			break;
		}
		if (ch == '0')
			break;
	}

}

void Menu::external_libraries_menu()
{
	for (;;)
	{

		system("cls");
		printf("\n");
		printf("\n                                     Zasoby bibliotek zewnetrznych\n\n");
		printf("                                            [1] Przeszukaj zasoby \n");
		printf("                                            [2] Wypozycz \n");
		printf("                                            [3] Zwroc \n");
		printf("                                            [0] Wyjdz \n");
		printf("\n");

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

				break;
			case '2':

				break;
			case '3':


				break;

			default:
			{
				//alert
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
		printf("\n");
		printf("\n                                              Uzytkownicy\n\n");
		printf("                                            [1] Wyswietl wszystkich uzytkownikow \n");
		printf("                                            [2] Znajdz uzytkownika po ID \n");
		printf("                                            [3] Dodaj nowego uzytkownika \n");
		printf("                                            [4] Usun uzytkownika \n");
		printf("                                            [0] Wyjdz \n");
		printf("\n");

		char ch, tmp;
		Functions functions;
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
				functions.find_user_byID(users);
				std::cout << std::endl;
				std::cout << "\n\n Wcisnij dowolny klawisz aby kontynuowac...";
				_getch();
				break;
			case '3':
				functions.add_new_user(users);
				break;
				
			case '4':
				functions.delete_user(users);
				break;

			default:
			{
				//alert
				continue;
			}
			}
			break;
		}
		if (ch == '0')
			break;

	}
}