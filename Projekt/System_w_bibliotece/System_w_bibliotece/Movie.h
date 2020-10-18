#pragma once
#include "Resource.h"
class Movie :
	public Resource
{
	Movie* next;
public:
	void show();

	void create_id();
};

