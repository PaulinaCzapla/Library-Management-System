#pragma once
#ifndef MENU_H
#define MENU_H
#include <iostream>

#include "LibraryUserActions.h"
#include "LibraryActions.h"

class Menu : public LibraryUserActions, public LibraryActions
{
public:
	void main_menu(Library&, Library&, Library&, List<Person>&);
	void resources_menu(Library&);
	void display_library_menu(Library&);
	void add_resource_menu(Library&);
	void external_libraries_menu(Library& ,Library&, Library&);
	void users_menu(List<Person>& );
	void libraries_menu(Library& ,Library&, Library&, short int);
};

#endif