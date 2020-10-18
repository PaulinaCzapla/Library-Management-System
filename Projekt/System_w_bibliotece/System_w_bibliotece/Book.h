#pragma once
#include "Resource.h"
class Book :
	public Resource
{
	Person* borrower;
public:
	void show();
	void create_id();
	
};

