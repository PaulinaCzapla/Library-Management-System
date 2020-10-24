#pragma once
#ifndef FILELIBRARY_H
#define FILELIBRARY_H
#include "File.h"

class FileLibrary :
    public File<Library>
{

public:
    FileLibrary(std::string);
    void write(Library&);
    void read(Library&);
};
#endif
