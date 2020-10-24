#pragma once
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Book.h"
#include "CD.h"
#include "Movie.h"


template<typename T>
class Node 
{
	Node* next, *prev;
	T data;

public:
	Node(T);
	Node(Node&);
	Node(T, Node<T>*, Node<T>*);
	void display();
	void set_next(Node*);
	Node * get_next();
	void set_prev(Node*);
	Node* get_prev();
	T& get_current_data();
	Node* get_current();
	Node& operator=(const Node&);
	bool operator==(const std::string&);

	~Node();
};


#endif