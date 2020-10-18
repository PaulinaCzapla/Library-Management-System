#pragma once
#include "Book.h"
template<class T>
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
	T* get_current();
	Node& operator=(const Node&);
	bool operator==(const std::string&);

	~Node();
};


