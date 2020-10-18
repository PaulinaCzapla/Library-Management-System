#pragma once
#include "Node.h"


template<typename T>
class List
{
	Node<T> * head;
	unsigned counter;

public: 
	List();
	Node<T>* push_front(Node<T>*); //dodaje na poczatek listy
	Node<T>* delete_element(Node<T>*); //usuwa wybrany element
	void display_list(); //wy�wietla ca�� list� 
	int size(); //zwraca ilo�� element�w listy
	Node <T>* get_element(std::string); //szukanie elementu po ID, zwraca znaleziony element albo nullptr

	~List();

};

