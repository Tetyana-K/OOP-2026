#include "Car.h"

Car::Car(const string& brand, int year)
	: brand(brand), year(year)
{
	this->brand = brand;
}
void Car::print() const  
{
	cout << "Car : '" << this->brand << "'\tYear : " << year << endl;
}

Car::~Car()
{
	cout << "~~~~~~ Destructor for " << brand << " done\n";
}