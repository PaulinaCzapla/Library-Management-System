#pragma once
#ifndef FILEPERSONALDATA_H
#define FILEPERSONALDATA_H
#include "File.h"



class FilePersonalData :
	public File< List<Person>>
{
public:
	FilePersonalData(std::string);
	void write(List<Person>&);
	void read(List<Person>&);
	~FilePersonalData() {};
};

#endif