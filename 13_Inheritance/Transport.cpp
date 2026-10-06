#include "Transport.h"

const string& Transport::getBrand() const
{
	return brand;
}

void Transport::setBrand(const string& brand)
{
	if (brand.empty())
		return;
	this->brand = brand;
}

Transport::Transport(const string& brand, int year)
	: year(year)
{
	//this->year = year;
	setBrand(brand);
	cout << "\t\tCtor for transport '" << brand << "'\n";
}

//void Transport::move() const
//{
//	cout << "Transport '" << brand << "' can move by ...????\n";
//}

void Transport::info() const
{
	cout << "Transport brand '" << brand << "\tYear : " << year << endl;
}

Transport::~Transport()
{
	cout << "\t\tDtor for transport '" << brand << "'\n";

}
