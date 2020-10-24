#pragma once
#include "File.h"


template<typename T>
class FilePersonalData :
	public File<T>
{
public:
	FilePersonalData(std::string);
	void write(List<Person>&);
	void read(List<Person>&);
};

