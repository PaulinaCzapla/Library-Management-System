#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <conio.h>
#include "Library.h"
#include "Person.h"
#include "List.h"
#include "Node.h"

class Functions
{
public:
	void borrow(Library*, List<Person>&);
	void make_a_return(Library*, List<Person>&);
	Node <Person>* find_user_byID(List<Person>&);
	void add_new_user(List<Person>&);
	void delete_user(List<Person>&);
};

#endif