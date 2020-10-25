#pragma once
#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "Functions.h"

class Menu
{
public:
	void main_menu(Library*, List<Person>&);
	void resources_menu();
	void external_libraries_menu();
	void users_menu(List<Person>& );
};

#endif