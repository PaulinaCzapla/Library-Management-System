#pragma once
#include <fstream>
#include <string>
#include "Text.h"
#include "Node.h"
#include "Date.h"
#include "Person.h"
#include "List.h"

#define FILENAME_PERSONAL_DATA "personal_data.txt"
#define FILENAME_MAIN_LIBRARY "library.txt"
#define FILENAME_MAIN_LIBRARY2 "library2.txt"
#define FILENAME_MAIN_LIBRARY3 "library3.txt"
#define FILENAME_BORROWED "borrowed_resources.txt"



template<typename T>
class File
{
protected:
	std::string filename;

public:
	File(std::string);
	virtual void write(T&) =0;
	virtual void read(T&) =0;
	bool check(std::fstream&);
};

