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

void Product::cmpByPrice(const Product& product1, const Product& product2)
{
	if (product1.price > product2.price)
		cout << product1.name << " has bigger price\n";
	else if (product1.price < product2.price)
		cout << product2.name << " has bigger price\n";
	else
		cout << "Products have same price\n";
}
