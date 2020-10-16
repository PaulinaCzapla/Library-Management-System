#pragma once
#include <iostream>



class Zespolona
{
public:
	float IM;
	float RE;
	static int licznik;


	Zespolona(float, float);
	Zespolona(float);
	Zespolona();
	Zespolona(Zespolona&);
	~Zespolona();
	void set_IM(float);
	void set_RE(float);
	float get_IM();
	float get_RE();
	void wyswietl();
	void pokaz_ile_obiektow();

	Zespolona& operator+ (const Zespolona&) const;
	Zespolona& operator- (const Zespolona&) const;
	const float& operator[] (bool) const;
	Zespolona& operator+=(const Zespolona&);
	bool operator!=(const Zespolona&);
	std::istream& operator>> (std::istream&);
	std::ostream& operator<< (std::ostream& output);
	Zespolona& operator=(const Zespolona&);
	bool operator==(const Zespolona&);
	Zespolona& operator ++();

	Zespolona& operator+= (float);
	//Zespolona& operator+= (float);
	//float operator+= (float);
	Zespolona& operator() (float, float);

};

