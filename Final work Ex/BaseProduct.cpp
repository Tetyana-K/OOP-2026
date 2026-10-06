#include "BaseProduct.h"

BaseProduct::BaseProduct(const string & name, double price)
	:name(name), price(price)
{
}

void BaseProduct::show() const
{
	cout << "Name : " << name << "\n" 
		<< "Price : " << price << endl;
}

void BaseProduct::input() 
{
	cout << "Enter name : ";
	std::cin >> name;
	cout << "Enter price : ";
	cin >> price;
}
