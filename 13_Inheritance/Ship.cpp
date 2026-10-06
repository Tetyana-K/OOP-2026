#include "Ship.h"

Ship::Ship(const string& brand, int year)
	: Transport(brand, year)
{
	cout << "\t\tCtor Ship '" << getBrand() << "'\n";
}

void Ship::move() const
{
	cout << "Ship '" << getBrand() << "' can swim\n";
}

Ship::~Ship()
{
	cout << "\t\tDtor Ship '" << getBrand() << "'\n";
}
