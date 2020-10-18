#include "Person.h"

Person::Person(std::string id_, std::string name_, Date date_, std::string address_, std::string phone_, List <Book*>* books_, List <CD*>* cds_, List <Movie*>* movies_)
{
	this->ID = id_;
	this->name = name;
	this->birth_date = date_;
	this->address = address_;
	this->phone_number = phone_;
	this->books = books_;
	this->cds = cds_;
	this->movies = movies_;
}


std::ostream& Person::operator<< (std::ostream& output)
{
	Text text;
	std::cout << " " << this->ID << " " << this->name << " " << this->birth_date << " " << this->address << " " << this->phone_number << " ";

	if (this->books)
	{
		std::cout << std::endl << std::endl;
		std::cout << " Wypozyczone ksiazki: " << std::endl;
		books->display_list();
	}
	if (this->books)
	{
		std::cout << std::endl << std::endl;
		std::cout << " Wypozyczone plyty: " << std::endl;
		cds->display_list();
	}
	if (this->books)
	{
		std::cout << std::endl << std::endl;
		std::cout << " Wypozyczone filmy: " << std::endl;
		movies->display_list();
	}

	
}