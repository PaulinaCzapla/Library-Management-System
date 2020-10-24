#include "Borrowed.h"

template <typename T>
Borrowed<T>::Borrowed(T data_, Date borrow_date_, Date deadline_)
{
	this->data = data_;
	this->borrow_date = borrow_date_;
	this->deadline = deadline_;
}

template <typename T>
Borrowed<T>::Borrowed()
{
	this->data;
	this->borrow_date_;
	this->deadline;
}

template <typename T>
void Borrowed<T>::display()
{
	std::cout << " " << this->data << " wypozyczono: " << this->borrow_date << " termin oddania: " << this->deadline;
}
template <typename T>

int Borrowed<T>::count_fine()
{
	int diff = this->deadline - this->borrow_date;

	if (diff < 0)
		return (diff * PRICE);
	else
		return 0;
}