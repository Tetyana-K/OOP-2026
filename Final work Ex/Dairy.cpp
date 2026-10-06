#include "Dairy.h"

Dairy::Dairy(const string& name, double price, int fat)
	:BaseProduct(name, price), fat(fat)
{
}

void Dairy::show() const
{
	BaseProduct::show();
	cout << "Fat : " <<fat << "%\n";
}

void Dairy::input()
{
	BaseProduct::input();
	cout << "Fat : ";
	cin >> fat;
}
