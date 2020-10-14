#include "Lista_zwierzatek.h"

#include <iostream>

Lista_zwierzatek::Lista_zwierzatek()
{
    head = nullptr;
    licznik = 0;
}

Lista_zwierzatek::~Lista_zwierzatek() //usuwanie ca³ej listy
{
    if (head)
    {
        Element_listy_zwierzatko* tmp;

        while (head)
        {
            tmp = head->zwroc_nastepny();
            delete head;
            head = tmp;
        }
    }
}
void Lista_zwierzatek::dodaj(Element_listy_zwierzatko* wsk)
{
    wsk->zmien_nastepny(Lista_zwierzatek::head);
    this->head = wsk;
    licznik++;
}

void Lista_zwierzatek::usun(Element_listy_zwierzatko* wsk)
{
    Element_listy_zwierzatko* tmp(head);

    if (head == wsk)
    {
        tmp = head->zwroc_nastepny();
        delete head;
        head = tmp;
    }
    else
    {
        Element_listy_zwierzatko* tmp2, * poprzedni(head);
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

void Lista_zwierzatek::wypisz()
{
    Element_listy_zwierzatko* tmp = head;
    int i = 1;
    while (head)
    {
        std::cout << " Element " << i << "= ";
        head->wyswietl();
        std::cout << std::endl;
        head = head->zwroc_nastepny();
        i++;
    }
    std::cout << std::endl << " Laczna liczba elementow: " << licznik;
    head = tmp;
}

void Lista_zwierzatek::wyswietl(Zwierzatko* zwierzatko)
{
    for (int i = 0; i < strlen(zwierzatko->zwroc_zwierzatko()); i++)
        std::cout << zwierzatko->zwroc_zwierzatko()[i];

    std::cout << std::endl;
}
