#include "List.h"

template<typename T>
List<T>::List()
{
	this->head = nullptr;
	this->counter = 0;
}

template<typename T>
Node<T>* List<T>::push_front(Node<T> *node_)
{
    counter++;
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
    
    counter--;
    return this->head;
}

template<typename T>
Node<T>* List<T>::get_element( std::string id)
{
    Node<T>* tmp(this->head);

    while (tmp)
    {
        if (tmp == id)
            return tmp;         
        else
            tmp = tmp->get_next();
    }
    return nullptr;
}

template<typename T>
void List<T>::display_list()
{
    Node<T>* tmp(this->head);

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
List<T>::~List()
{
    Node <T> * p;

    while (this->head)
    {
        counter--;
        p = this->head->get_next();
        delete this->head;
        this->head = p;
    }
    this->head = nullptr;
}