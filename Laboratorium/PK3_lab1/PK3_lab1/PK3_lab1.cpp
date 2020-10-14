#include "Liczba_zespolona.h"
#include "Lista.h"
#include "Element_listy.h"
#include "Tablica_dwuwymiarowa.h"
#include "Zwierzatko.h"
#include "Wskaznik.h"
#include <iostream>
#include "Tablica_dwm_zwierzatka.h"
#include "Lista_zwierzatek.h"
#include "Element_listy_zwierzatko.h"
#include <utility>
#include <cstdlib>
#include <ctime>

void losuj()
{
    int w,k,j=0;

    std::cout << " Losowanie zwierzatek z tablicy. Podaj ilosc wierszy w tablicy:  ";
    std::cin >>w ;
    std::cout << std::endl<<" Podaj ilosc kolumn:  ";
    std::cin >> k;
    std::cout << std::endl;

    Tablica_dwm_zwierzatka tab(k, w);
   
    char tmp;
    std::string n;
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < k; j++)
        {
            std::cout << " Podaj zwierzatko: ";
            std::cin >> n;
           
            char * nazwa = new char[n.length()+1];
            for (int i = 0; i < n.length(); i++)
            {
                nazwa[i] = n[i];
            }
            nazwa[n.length()] = '\0';

          
            Zwierzatko zwierze(nazwa);
            tab.dodaj(zwierze, i, j);
        }
    }
    int x1 = rand() % k + 0;
    int x2 = rand() % w + 0;

    std::cout << " Zwierzatko wylosowane z tablicy to:  " << tab.wyswietl(x2, x1).zwroc_zwierzatko()<<std::endl;
  


}
int main()
{
    srand(time(NULL));
    //Lista lista;
    //Liczba_zespolona liczba;
   // Element_listy* element;

    //element = new Element_listy(liczba);
    //lista.dodaj(element);

    //liczba.set_IM(2);
    //liczba.set_RE(2);
    //element = new Element_listy(liczba);
    //lista.dodaj(element);

    //liczba.set_IM(3);
    //liczba.set_RE(3);
    //element = new Element_listy(liczba);
    //lista.dodaj(element);

    //liczba.set_IM(4);
    //liczba.set_RE(4);
    //element = new Element_listy(liczba);
    //lista.dodaj(element);

    //lista.wypisz();


 //   Liczba_zespolona liczba(2, 2);
 //   Liczba_zespolona liczba2(2, 3);
 //
 //   Wskaznik p(liczba);
 //   Wskaznik p2(liczba2);
 //   Wskaznik p3(std::move(p2));
 //   Wskaznik p4(std::move(p));

 ///*  p.wyswietl();
 //   p2.wyswietl();*/
 //   p3.wyswietl();
 //   p4.wyswietl();
 //   liczba.pokaz_ile_obiektow();
    //p3.ile();

    losuj();
}
