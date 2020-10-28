
#include <iostream>
#include "dekoder.h"
#include "Odtwarzacz.h"


int main()
{
	

	Dekoder dekoder; // konstruktory wywo³ywane s¹ w kolejnoœci: DabPlus, MP3, MPG,RadioFM, Dekoder 

	dekoder.ustaw_moc(30);
	dekoder.wyswietl_moc();

std::cout << " --------------------------------------------------------------------\n";

	Odtwarzacz odtwarzacz; // konstruktory wywo³ywane s¹ w kolejnoœci: MPG,MPG2, MPG4, odtwarzacz
							// Wyst¹pi³ problem rombu - pola MPG wystêpuj¹ dwukrotnie
						   //Problem rombu zosta³ rozwi¹zany przez zastosowanie dziedziczenia wirtualnego
	odtwarzacz.dekoduj();
	odtwarzacz.wypisz_format();
}

