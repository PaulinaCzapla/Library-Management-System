#include "Zespolona.h"

#include <iostream>

int Zespolona::licznik = 0;

Zespolona::Zespolona(float rez, float imz)
{
	licznik++;
	IM = imz;
	RE = rez;
}

Zespolona::Zespolona(float rez)
{
	licznik++;
	IM = 0;
	RE = rez;
}
Zespolona::Zespolona()
{
	licznik++;
	IM = 0;
	RE = 0;
}
Zespolona::Zespolona(Zespolona& liczba)
{
	licznik++;
	IM = liczba.IM;
	RE = liczba.RE;
}

Zespolona::~Zespolona()
{
	Zespolona::licznik--;
}

void Zespolona::set_IM(float IM)
{
	this->IM = IM;
}

void Zespolona::set_RE(float RE)
{
	this->RE = RE;
}

float Zespolona::get_IM()
{
	return IM;
}

float Zespolona::get_RE()
{
	return RE;
}

void Zespolona::wyswietl()
{
	std::cout << " RE=" << this->RE <<" IM=" << this->IM <<  std::endl;
}

void Zespolona::pokaz_ile_obiektow()
{
	std::cout << " W programie jest " << licznik << " liczb zespolonych. " << std::endl;
}

Zespolona& Zespolona::operator+= (const Zespolona& z2)
{
	std::cout << " Zespolona& Zespolona::operator+= (const Zespolona& z2) " << std::endl;
	this->IM = this->IM + z2.IM;
	this->RE = this->RE + z2.RE;

	return *this;
}

Zespolona& Zespolona::operator+ (const Zespolona& z2) const
{
	std::cout << " Zespolona& Zespolona::operator+ (const Zespolona& z2) const " << std::endl;
	Zespolona* z3 = new Zespolona(this->IM + z2.IM, this->RE + z2.RE);
	return *z3;
}

Zespolona& Zespolona::operator- (const Zespolona& z2) const
{
	std::cout << " Zespolona& Zespolona::operator- (const Zespolona& z2) const " << std::endl;
	Zespolona* z3 = new Zespolona(this->IM - z2.IM, this->RE - z2.RE);

	return *z3;
}

const float & Zespolona::operator[](bool n) const
{
	std::cout << " const float & Zespolona::operator[](bool n) const " << std::endl;
	if (n)
		return this->RE;
	else
		return this->IM;

}

bool Zespolona::operator!=( const Zespolona& z2)
{
	std::cout << " bool Zespolona::operator!=( const Zespolona& z2) " << std::endl;
	if (this->IM == z2.IM && this->RE == z2.RE)
		return false;
	else true;
}


std::istream& Zespolona::operator>> (std::istream& input)
{
	std::cout << " std::istream& Zespolona::operator>> (std::istream& input) " << std::endl;
	float a, b;
	input >> a >> b;
	this->RE = a;
	this->IM = b;

	return input;
}

std::ostream& Zespolona::operator<< (std::ostream& output)
{
	std::cout << " std::ostream& Zespolona::operator<< (std::ostream& output) " << std::endl;
	output << "Liczba rzeczywista: " << this->RE << " liczba zespolona: " << this->IM << std::endl;
	return output;
}


Zespolona& Zespolona::operator=(const Zespolona& z)
{
	std::cout << " Zespolona& Zespolona::operator=(const Zespolona& z) " << std::endl;
	this->RE = z.RE;
	this->IM = z.IM;

	return *this;

}

bool Zespolona::operator==(const Zespolona& z2)
{
	std::cout << " bool Zespolona::operator==(const Zespolona& z2) " << std::endl;
	if (this->IM == z2.IM && this->RE == z2.RE)
		return true;
	else false;
}


Zespolona& Zespolona::operator++()
{
std::cout << " Zespolona& Zespolona::operator++() " << std::endl;
	this->RE = this->RE + 1;
	return *this;
}

Zespolona& Zespolona::operator+= (float num)
{
	std::cout << " Zespolona& Zespolona::operator+= (float num) " << std::endl;
	this->IM = this->IM + num;
	this->RE = this->RE + num;

	return *this;
}


//Zespolona& Zespolona::operator+= (float num)
//{
//std::cout << " Zespolona& Zespolona::operator+= (float num)" << std::endl;
//	this->IM = this->IM + num;
//
//	return *this;
//}
//
//float Zespolona::operator+= (float num)
//{
//std::cout << " float Zespolona::operator+= (float num) " << std::endl;
//	num += this->get_RE;
//
//	return num;
//}

Zespolona& Zespolona::operator() (float re, float im)
{
	this->RE = re;
	this->IM = im;
	return *this;
}