
#include <iostream>

#include "Email.h"
#include "LiczbaRzymska.h"
#include "Telefonstat.h"
#include "Telefonkom.h"
#include "Kwota.h"
#include "Przelew.h"
#include "PrzelewPrzyOdbiorze.h"
#include "Blysk.h"
#include "Ogien.h"
#include "Dym.h"
#include "Deszcz.h"
#include"Wybuch.h"


void info(bool walidacja)
{
	if (walidacja == true)
		std::cout << " Prawidlowa wartosc " << std::endl;
	else
		std::cout << " Nieprawidlowa wartosc " << std::endl;
}

int main()
{
	//    ZAD1
	Telefonkom komorka_dobra("980567234");
	Telefonkom komorka_dobra2("+48980567234");
	Telefonkom komorka_zla("34f39242");
	LiczbaRzymska liczba_dobra("XII");
	LiczbaRzymska liczba_zla("X78");
	Email email_dobry("dsfdsf@email.com");
	Email email_zly("as@jdddddsd");
	Telefonstat stat_dobry("(32)8787123");
	Telefonstat stat_zly("048090087");
	Kwota kwota_dobra("12,70");
	Kwota kwota_zla("23,9890");

	info(komorka_dobra.sprawdz());
	info(komorka_dobra2.sprawdz());
	info(komorka_zla.sprawdz());
	info(liczba_dobra.sprawdz());
	info(liczba_zla.sprawdz());
	info(email_dobry.sprawdz());
	info(email_zly.sprawdz());
	info(stat_dobry.sprawdz());
	info(stat_zly.sprawdz());
	info(kwota_dobra.sprawdz());
	info(kwota_zla.sprawdz());

// ===================================================================================================== ZAD2

	
	Przelew przelew(1, "PLN");
	przelew.nalicz_oplate("10,99");
	przelew.wykonaj_platnosc();

	// =============================================================================================== ZAD 3

	Blysk blysk;
	Wybuch wybuch;
	Deszcz deszcz;
	Ogien ogien;
	Dym dym;

	blysk.wywolaj();

}
