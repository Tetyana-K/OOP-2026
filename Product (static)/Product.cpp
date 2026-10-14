#include <iostream>
using namespace std;
#include "Product.h"

int Product::counter = 0; // реаліз (визначення) статичного поля за межами класу


Product::Product(const string& name, int price)
	: name(name), price(price)
{
	++counter;// полічили на 1 об'єкт більше - щойно створили об'єкт
}

void Product::print() const
{
	cout << name << "\t" << price << endl;
}
