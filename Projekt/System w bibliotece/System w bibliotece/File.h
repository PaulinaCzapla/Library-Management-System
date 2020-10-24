#pragma once
#include <fstream>
#include "Text.h"
#include "Node.h"

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

