#pragma once
#include "ResourcesActions.h"
#include "Person.h"

class LibraryActions :
	public ResourcesActions
{
public:
	LibraryActions() {};
	void borrow(Library&, List<Person>&);
	void make_a_return(Library&, List<Person>&);
	bool search_library_IDs(Library&);
	bool search_library_titles(Library&);
	void show_imported_resources(Library&, std::string&);
	void import_resource(Library&, Library&);
};

