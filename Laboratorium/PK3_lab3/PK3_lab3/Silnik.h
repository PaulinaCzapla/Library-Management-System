#pragma once
class Silnik
{
public:
	bool stan;
	int szybkosc;
	int identyfikator;

private:
	Silnik& operator=(const Silnik& silnik)
	{
		this->stan = silnik.stan;
		this->szybkosc = silnik.szybkosc;
		this->identyfikator = silnik.identyfikator;

		return *this;
	}

};

