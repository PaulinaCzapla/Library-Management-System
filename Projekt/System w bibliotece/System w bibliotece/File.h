#pragma once
#include <fstream>
class File
{
protected:
	std::fstream file;

public:
	virtual void save() =0;
	virtual void read() =0;
};

