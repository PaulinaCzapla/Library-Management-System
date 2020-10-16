// lab2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include "zespolona.h"
#include <iostream>



//Zespolona& operator+(const Zespolona& z1, const Zespolona& z2)
//{
//    Zespolona* z3 = new Zespolona (z1.IM + z2.IM, z1.RE+z2.RE);
// 
//    return *z3;
//}
//
//Zespolona& operator-(const Zespolona& z1,const Zespolona& z2)
//{
//    Zespolona* z3 = new Zespolona(z1.IM - z2.IM, z1.RE - z2.RE);
//
//    return *z3;
//}

bool operator !=(const Zespolona& z1,const Zespolona& z2)
{
    if (z1.IM == z2.IM && z1.RE == z2.RE)
        return false;
    else true;
}

bool operator ==(const Zespolona& z1, const Zespolona& z2)
{
    if (z1.IM == z2.IM && z1.RE == z2.RE)
        return true;
    else false;
}

std::istream& operator>> (std::istream& input, Zespolona& z)
{
    float a, b;
    input >> a >> b;
    z.set_RE(a);
    z.set_IM(b);

    return input;
}

std::ostream& operator<< (std::ostream& output, Zespolona const& z)
{
    output << "Liczba rzeczywista: " << z.RE << " liczba zespolona: " << z.IM << std::endl;
    return output;
}

Zespolona& operator++(Zespolona& z)
{
    z.RE = z.RE + 1;
    return z;
}


int main()
{
    Zespolona z1 (2, 3);
    Zespolona  z2 (3, 3);
    std::cout << z1;
    z1 += z2;
    z1.wyswietl();
    Zespolona z3 = z1 + z2;
    z3.wyswietl();
    if (z1 != z2)
        std::cout << z1;
    Zespolona z4;
    std::cin >> z4;
    z4.wyswietl();
    std::cout << z4[1]<<"   "<<z4[0]<<std::endl;
    

}

