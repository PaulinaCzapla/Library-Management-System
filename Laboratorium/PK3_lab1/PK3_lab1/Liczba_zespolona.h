#pragma once
class Liczba_zespolona
{
	float IM;
	float RE;
	static int licznik;

public:
	Liczba_zespolona(float, float);
	Liczba_zespolona(float);
	Liczba_zespolona();
	Liczba_zespolona(Liczba_zespolona&);
	~Liczba_zespolona();
	void set_IM(float);
	void set_RE(float);
	float get_IM();
	float get_RE();
	void wyswietl();
	void pokaz_ile_obiektow();

};

