
#include <iostream>
#include "Samolot.h"


void funkcja(Samolot samolot_) //wykorzystywany jest tu konstruktor kopiujący wygenerowany przez kompilator
{
    std::cout <<samolot_.dystans<<" "<< samolot_.paliwo<<"  "<<samolot_.wysokosc<<std::endl;
}

Samolot korekta(Samolot samolot, float korekta)//wykorzystywany jest tu konstruktor kopiujący wygenerowany przez kompilator
{
    Samolot kopia(samolot);
    kopia.wysokosc -= korekta;
    return kopia;
}
int main()
{
    Samolot samolot; //konstruktor domyślny jest generowany przez kompilator tylko wtedy, gdy nie zostały zadeklarowane inne konstruktory 
    samolot.dystans = 1000;
    samolot.paliwo = 324;
    samolot.wysokosc = 2000;
    //samolot.x = 234;
    //samolot.z = 923;
    //samolot.y = 933;
    samolot.set_x(342);
    samolot.set_y(546);
    samolot.set_z(342);
    
    
    char* tab = new char[10];

    for (int i = 0; i < 10; i++)
        tab[i] = 'a' + i;

    samolot.sygnatura = tab; //tablica zostaje przypisana
 Samolot s2, s3; //obiekt z pustymi polami

 s2 = samolot; //wszystkie dane zostają przypisane
 funkcja(s2);



 s3 = korekta(s2, 122); // konstruktor kopiujący przestał działać po dodaniu pola psilnik
 funkcja(s3);
    //Samolot s(234, 2344, 4343,455,234,324); //błąd - brak konstruktora wieloargumentowego. Konstruktor wieloargumentowy nie jest domyślny.

    Samolot sam(korekta(samolot, 2334));
    funkcja(sam);

   

   // samolot = s2; //błąd - nie można przypisać wartości stworzonej konstruktorem domyślnym wygenerowanym przez kompilator, ponieważ ma puste pola
    s2 = samolot; // wykonuje się poprawnie, nawet jak pola są prywatne. Błąd "usunięta funkcja" po dodaniu const int jako atrybut klasy.

    funkcja(s2);
    funkcja(samolot);
   // funkcja(samolot);
   // s.~Samolot();

   // funkcja(samolot);
    //samolot = s;
   // s = samolot;
   // funkcja(s);

    Silnik silnik;
    silnik.identyfikator = 23;
    silnik.stan = 1;
    silnik.szybkosc = 93242;

    Silnik silnik2(silnik);

    //samolot.psilnik = silnik; // operatora przypisania nie można użyć poza klasą

    //silnik2 = silnik; // operator przypidania jest niedostępny

}


// ODPOWIEDZI DO ZADAŃ
//2. Użycie konstruktora wieloargumentowego bez wcześniejszej implementacji,
// powoduje wywołanie błędu. Kompilator nie generuje automatycznie konstruktora wieloargumentowego.
//3.Użycie konstruktora bezargumentowego, podczas gdy klasa nie ma zaimplementowanych żadnych konstruktorów, 
// skutkuje stworzeniem obiektu, którego wszystkie wartości są nieprzypisane. W przypadku gdy klasa ma już zaimplementowany jakiś konstruktor np. wieloargumentowy,
// próba wywołania konstruktora domyślnego kończy się błędem kompilacji. Kompilator generuje konstruktor bezargumentowy.
//4. Wywołanie destruktora nie powoduje błędu kompilacji. Destruktory są generowane automatycznie przez
// kompilator. Każda klasa musi mieć swój destruktor, niezależnie od tego czy programista go zaimplementuje.
//5. Przy wywoływaniu funkcji wykorzystywany jest konstruktor kopiujący, obiekt samolot_ jest kopią obiektu podanego jako parametr funkcji.
// Konstruktor kopiujący został wygenerowany automatycznie przez kompilator.
//6. Konstruktor kopiujący wykorzystany w funkcji, jest generowany automatycznie. Konstruktor kopiujący został w tej funkcji wykorzystany trzy razy:
// podczas przekazywania obiektu jako parametr,  przy stworzeniu kopii Samolot kopia(samolot); oraz przy zwrocie wartości funkcji.
// 7. samolot = s2; - wywołuje błąd kompilacji
//    s2 = samolot; - prawidłowo przypisuje wartości
// Kompilator generuje operator przypisania.
//8. Nie nastąpiła zmiana w działaniu operatora przypisania po zmienieniu pól x,y,z na prywatne.
//9. Przy użyciu konstruktora kopiującego wygenerowanego przez kompilator, tablica dynamiczna Sygnatura nie jest kopiowana. Obiekt skopiowany i kopia posiadają ten
// sam wskaźnik na tablicę.
//10. Pojawia się błąd przy próbach wywołania konstruktorów i operatora przypisania - "usunięta funkcja"
// 11. Operator przypisania jest niedostępny globalnie. Można go użyć tylko wewnątrz klasy.
// 12. Błąd przy próbie przypisania do siebie obiektów samolot - "usunięta funkcja". Operator przypisania nie działa, ponieważ operator przypisania w klasie Silnik jest prywatny.
//14. Konstruktor domyslny klasy Samolot został usunięty.
//15. Operator przeniesienia i konstruktor przenoszący są generowane automatycznie, o ile programista nie stworzy własnych.