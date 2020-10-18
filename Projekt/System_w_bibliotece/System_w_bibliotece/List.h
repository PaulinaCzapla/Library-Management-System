#pragma once
#include "Node.h"


template<typename T>
class List
{
	Node<T> * head;
	unsigned counter;

public: 
	List();
	Node<T>* push_front(Node<T>*);
	Node<T>* delete_element(Node<T>*);
	void display_list();
	unsigned size();
	Node <T>* get_element(std::string); //szukanie elementu po ID

	~List();

};

