#include "FilePersonalData.h"
#include <fstream>
#include <string>
List <class Person>* FilePersonalData::read()
{
	File::file.open("PersonalData.txt", std::ios::out);

	List <class Person>* list = new List <class Person>;
	

	while (!file.eof())
	{
		std::istream& getline(char* odczytane_dane, std::streamsize ilosc_danych, char znak_konca_linii);
	}
}