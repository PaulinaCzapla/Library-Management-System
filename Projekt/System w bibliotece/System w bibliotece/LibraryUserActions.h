#pragma once
#include "List.h"
#include "Person.h"
#include <conio.h>

class LibraryUserActions
{
	Text text;
public:
	LibraryUserActions() {};
	Node <Person>* find_user_byID(List<Person>&);
	void add_new_user(List<Person>&);
	void delete_user(List<Person>&);
};

