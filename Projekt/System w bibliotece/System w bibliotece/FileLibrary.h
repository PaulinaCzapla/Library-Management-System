#pragma once
#include "File.h"
#include "Library.h"
template<typename T>

class FileLibrary :
    public File<T>
{

public:
    FileLibrary(std::string);
    void write(Library&);
    void read(Library&);
};

