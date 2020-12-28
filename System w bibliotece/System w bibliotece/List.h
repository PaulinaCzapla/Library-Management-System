#pragma once
#ifndef LIST_H
#define LIST_H
#include "Node.h"

template<typename T>
class List
{
	Node<T>* head;
	unsigned counter;

public:
	List();
	Node<T>* push_front(Node<T>*); //dodaje na poczatek listy
	Node<T>* delete_element(Node<T>*); //usuwa wybrany element
	void display_list(); //wyœwietla ca³¹ listê 
	int size(); //zwraca iloœæ elementów listy
	Node<T>* get_head();
	Node <T>* get_element(std::string); //szukanie elementu po ID, zwraca znaleziony element albo nullptr
	Node <T>* get_element(T&);
	void set_counter(int);
	void increase_counter();
	T& get_data(Node<T>*);
	~List();
};




template<typename T>
List<T>::List()
{
	this->head = nullptr;
	this->counter = 0;
}

template<typename T>
Node<T>* List<T>::push_front(Node<T>* node_)
{
	node_->set_next(this->head);
	node_->set_prev(nullptr);

	if (this->head)
		this->head->set_prev(node_);
	this->head = node_;

	return this->head;
}

template<typename T>
Node<T>* List<T>::delete_element(Node<T>* node_)
{
	Node<T>* tmp;

	if (node_->get_prev())
		node_->get_prev()->set_next(node_->get_next());
	else
		this->head = node_->get_next();

	if (node_->get_next())
		node_->get_next()->set_prev(node_->get_prev());

	delete node_;
	node_ = nullptr;

	return this->head;
}

template<typename T>
Node<T>* List<T>::get_element(std::string id)
{
	Node<T>* tmp = this->head;

	while (tmp)
	{
		if (tmp->get_current_data() == id)
			return tmp;
		else
			tmp = tmp->get_next();
	}
	return nullptr;
}


template<typename T>
Node<T>* List<T>::get_element(T& data)
{
	Node<T>* tmp = this->head;

	while (tmp)
	{
		if (tmp->get_current_data() == data)
			return tmp;
		else
			tmp = tmp->get_next();
	}
	return nullptr;
}


template<typename T>
void List<T>::display_list()
{
	Node<T>* tmp = this->head;

	while (tmp)
	{
		tmp->display();
		tmp = tmp->get_next();
	}
}

template<typename T>
int List<T>::size()
{
	return this->counter;
}

template<typename T>
void List<T>::set_counter(int counter_)
{
	this->counter = counter_;
}

template<typename T>
void List<T>::increase_counter()
{
	this->counter++;
}

template<typename T>
T& List<T>::get_data(Node<T>* node)
{
	return node->get_current_data();
}

template<typename T>
Node<T>* List<T>::get_head()
{
	return head;
}

template<typename T>
List<T>::~List()
{
	Node <T>* p;

	while (this->head)
	{
		p = this->head->get_next();
		delete this->head;
		this->head = p;
	}
	this->head = nullptr;
}

#endif