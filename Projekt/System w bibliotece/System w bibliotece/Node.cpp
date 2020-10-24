#include "Node.h"


template<typename T>
Node<T>::Node(T data_) 
{
	this->data = data_;
	this->next = nullptr;
	this->prev = nullptr;
}

template <typename T>
Node<T>::Node(Node<T>& node_)
{
	this->data = node_->data;
	this->next = node_->next;
	this->prev = node_->prev;
}

template <typename T>
Node<T>::Node(T data_, Node<T>* next_, Node<T>* prev_)
{
	this->data = data_;
	this->next = next_;
	this->prev = prev_;
}

template <typename T>
void Node<T>::display()
{
	std::cout << data;
}



template <typename T>
void Node<T>::set_next(Node<T>* next_)
{
	this->next = next_;
}

template <typename T>
Node<T>* Node<T>::get_next()
{
	return this->next;
}

template <typename T>
void Node<T>::set_prev(Node<T>* prev_)
{
	this->prev = prev_;
}

template <typename T>
Node<T>* Node<T>::get_prev()
{
	return this->prev;
}


template <typename T>
T& Node<T>::get_current()
{
	return this->data;
}

template <typename T>
Node<T>& Node<T>::operator=(const Node<T>& other)
{
	this->next = other->next;
	this->data = other->data;

	return*this;
}

template <typename T>
bool Node<T>::operator==(const std::string& id)
{
	if (this->data == id)
		return true;
	else
		return false;
}

template <typename T>
Node<T>::~Node()
{

}