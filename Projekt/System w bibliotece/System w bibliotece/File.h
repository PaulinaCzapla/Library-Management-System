#pragma once
#ifndef FILE_H
#define FILE_H
#include <fstream>
#include <string>
#include "Text.h"
#include "Person.h"//date library list node borrowed
#include "Node.cpp"
#include "List.cpp"


#define FILENAME_PERSONAL_DATA "personal_data.txt"
#define FILENAME_MAIN_LIBRARY "library.txt"
#define FILENAME_LIBRARY2 "library2.txt"
#define FILENAME_LIBRARY3 "library3.txt"
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

#endif