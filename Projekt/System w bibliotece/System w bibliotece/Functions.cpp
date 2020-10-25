#include "Functions.h"


void Functions::borrow(Library* libraries, List<Person>& users)
{
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
		text.display_red(" Nie istnieje taki zasób. ");
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
			Borrowed borrowed (resource_id, today, deadline);
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
	puts("\n\n Wcisnij dowolny klawisz aby kontynuowac...");
	getch();

}
