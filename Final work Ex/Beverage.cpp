#include "Beverage.h"

void Beverage::show() const
{
	BaseProduct::show();
	cout << "Volume : " << volume << endl;
}

void Beverage::input()
{
	BaseProduct::input();
	cout << "Volume : ";
	cin >> volume;
}
