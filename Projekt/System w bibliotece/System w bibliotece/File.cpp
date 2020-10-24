#include "File.h"


template<typename T>
File<T>::File<T>(std::string filename_) : filename(filename_) {}

template<typename T>
bool File<T>::check(std::fstream& file)
{
	if (file.is_open() && file.good())
		return true;
	else
		return false;
}
