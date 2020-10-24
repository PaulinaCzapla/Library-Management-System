#pragma once
#ifndef FILEBORROWED_H
#define FILEBORROWED_H
#include "File.h"
#include "File.cpp"

class FileBorrowed :
    public File<List<Person>>
{
public:
	FileBorrowed(std::string);
	void write(List<Person>&);
	void read(List<Person>&);
};

#endif

