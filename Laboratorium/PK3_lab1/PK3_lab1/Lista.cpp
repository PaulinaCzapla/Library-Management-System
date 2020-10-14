#include "Lista.h"
#include <iostream>

Lista::Lista()
{
	head = nullptr;
	licznik = 0;
}

Lista::~Lista() //usuwanie ca³ej listy
{
    if (head)
    {
        Element_listy* tmp;

        while (head)
        {
            tmp = head->zwroc_nastepny();
            delete head;
            head = tmp;
        }
    }
}
void Lista::dodaj(Element_listy* wsk) 
{
	wsk->zmien_nastepny(Lista::head);
	this->head = wsk;
	licznik++;
}

void Lista::usun(Element_listy* wsk)
{
    Element_listy* tmp(head);

    if (head == wsk)
    {
        tmp = head->zwroc_nastepny();
        delete head;
        head = tmp;
    }
    else
    {
        Element_listy* tmp2, *poprzedni(head) ;
        while (tmp)
        {
            if (tmp == wsk)
            {       
                tmp2 = tmp->zwroc_nastepny();
                delete tmp;
                poprzedni->zmien_nastepny(tmp2);
                break;
            }
            poprzedni = tmp;
            tmp = tmp->zwroc_nastepny();
        }
    }
}

void Lista::wypisz()
{
    Element_listy* tmp = head;
    int i = 1;
    while (head)
    {
        std::cout << " Element "<<i<<"= ";
        head->wyswietl();
        std::cout << std::endl;
        head = head->zwroc_nastepny();
        i++;
    }
    std::cout << std::endl << " Laczna liczba elementow: " << licznik;
    head = tmp;
}