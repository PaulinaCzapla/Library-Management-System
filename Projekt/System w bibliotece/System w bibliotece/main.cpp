
#include <iostream>
#include "Menu.h"
//#include "List.h"
//
//#include "Book.h"
//#include "CD.h"
//
//#include "Movie.h"
#include "Resource.h"
#include "Node.h"
//#include "Node.cpp"
//#include "List.cpp"
//
//#include "File.h"
//#include "Library.h"
#include "FileBorrowed.h"
#include "FileLibrary.h"
#include "FilePersonalData.h"
#include"Person.h"
#include "Borrowed.h"

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

std::ostream& operator<< (std::ostream& output, Resource const& data)
{
	Text text;
	std::cout << " " << data.ID << "    " << data.authors_name<< " | " << data.title  << " | rok wydania:" << data.release_date << " ";

	if (data.is_available)
	{
		text.display_green(" Dostepny. ");
		std::cout << std::endl << std::endl;
	}

	else
	{
		text.display_red(" Niedostepny. ");
		std::cout << std::endl << std::endl;
	}
	return output;
}

std::ostream& operator<< (std::ostream& output, Date const& date)
{
	if (date.day == 0 || date.month == 0)
		std::cout << " " << date.year;
	else if (date.day < 10 && date.month < 10)
		std::cout << " 0" << date.day << ".0" << date.month << "." << date.year;
	else if (date.day < 10)
		std::cout << " 0" << date.day << "." << date.month << "." << date.year;
	else if (date.month < 10)
		std::cout << " " << date.day << ".0" << date.month << "." << date.year;
	else
		std::cout << " " << date.day << "." << date.month << "." << date.year;

	return output;
}

std::ostream& operator<< (std::ostream& output, Person& data)
{
	//std::cout << " " << data.ID << "  |  " << data.name << "  |  " << data.birth_date << "  |  " << data.address << "  |  " << data.phone_number << std::endl;
	printf("\n ID %-10s  |  %-23s  |  %-10s  |  tel. %-9s  |  %-s", data.ID.c_str(), data.name.c_str(), data.birth_date.date_to_string().c_str(), data.phone_number.c_str(), data.address.c_str());
	data.borrowed_resources.display_list();
	std::cout << std::endl;
	return output;
}

std::ostream& operator<< (std::ostream& output, Borrowed & data)
{
	//std::cout << "                " << data.resource_ID << " wypozyczono: " << data.borrow_date << "   termin zwrotu: " << data.deadline << std::endl;
	printf("\n                 |   ID %-19s  |  wypozyczono: %-16s  |  termin zwrotu: %-10s  \n", data.resource_ID.c_str(), data.borrow_date.date_to_string().c_str(), data.deadline.date_to_string().c_str());
	return output;
}

//template <typename T>
//bool operator==(T& o, std::string id)
//{
//	return false;
//}
//bool operator ==(const Person& person, const std::string& id)
//{
//	if (id.compare(person.ID) == 0)
//		return true;
//	else
//		return false;
//}
//
//bool operator ==(const Resource& resource, const std::string& id)
//{
//	if (id.compare(resource.ID) == 0)
//		return true;
//	else
//		return false;
//}


//bool operator ==(const Person& person, const std::string& id)
//{
//	if (id.compare(person.ID) == 0)
//		return true;
//	else
//		return false;
//}
//
//template <typename T>
//bool operator==(T& o, std::string id)
//{
//	return false;
//}

//bool operator ==(const Person& person, const Person& person2)
//{
//	if (person.ID == person.ID)
//		return true;
//	else
//		return false;
//}

int main()
{
	{
		FileLibrary file_main_library(FILENAME_MAIN_LIBRARY);
		FileLibrary file_library2(FILENAME_LIBRARY2);
		FileLibrary file_library3(FILENAME_LIBRARY3);

		Library main_library;
		Library library2;
		Library library3;

		file_main_library.read(main_library);
		file_library2.read(library2);
		file_library3.read(library3);


		FilePersonalData personal_data(FILENAME_PERSONAL_DATA);
		List<Person> users;
		personal_data.read(users);

		FileBorrowed borrowed(FILENAME_BORROWED);
		borrowed.read(users);
	
		
		Menu menu;
		Sleep(1000);
		menu.main_menu(main_library, library2, library3, users);

		file_main_library.write(main_library);
		file_library2.write(library2);
		file_library3.write(library3);

		personal_data.write(users);

		borrowed.write(users);
		

	}


_CrtDumpMemoryLeaks();
return 0;
}
