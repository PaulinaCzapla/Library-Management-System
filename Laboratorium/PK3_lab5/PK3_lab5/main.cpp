
#include <iostream>
#include "dekoder.h"
#include "Odtwarzacz.h"


int main()
{
	

	Dekoder dekoder; // konstruktory wywo�ywane s� w kolejno�ci: DabPlus, MP3, MPG,RadioFM, Dekoder 

	dekoder.ustaw_moc(30);
	dekoder.wyswietl_moc();

std::cout << " --------------------------------------------------------------------\n";

	Odtwarzacz odtwarzacz; // konstruktory wywo�ywane s� w kolejno�ci: MPG,MPG2, MPG4, odtwarzacz
							// Wyst�pi� problem rombu - pola MPG wyst�puj� dwukrotnie
						   //Problem rombu zosta� rozwi�zany przez zastosowanie dziedziczenia wirtualnego
	odtwarzacz.dekoduj();
	odtwarzacz.wypisz_format();
}

