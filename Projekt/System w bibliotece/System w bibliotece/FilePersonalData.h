#pragma once
#include "File.h"
#include "List.h"
#include "Person.h"

class FilePersonalData :
	public File
{

public:
	List <class Person> * read();
};

