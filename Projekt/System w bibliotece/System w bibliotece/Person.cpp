#include "Person.h"

Person::Person(std::string id_, std::string name_, Date date_, std::string address_, std::string phone_, List <Borrowed<Book>*>* books_, List <Borrowed<CD>*>* cds_, List <Borrowed<Movie>*>* movies_)
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

