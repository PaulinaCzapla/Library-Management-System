
#include <iostream>
#include "Menu.h"
#include "Resource.h"
#include "Node.h"
#include "FileBorrowed.h"
#include "FileLibrary.h"
#include "FilePersonalData.h"
#include"Person.h"
#include "Borrowed.h"

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

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
