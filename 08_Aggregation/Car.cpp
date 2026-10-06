#include "Car.h"

Car::Car(const string& brand, int year)
	: brand(brand), year(year)
{
}
void Car::print() const
{
	cout << "Car : '" << brand << "'\tYear : " << year << endl;
}