#pragma once
class Zwierzatko
{
	char* zwierzatko;
	int numer;
	static int licznik;

public:
	Zwierzatko(char*);
	Zwierzatko();
	Zwierzatko(Zwierzatko&);
	~Zwierzatko();
	void zmien_zwierzatko(char*);
	char* zwroc_zwierzatko();
	int zwroc_numer();

};

