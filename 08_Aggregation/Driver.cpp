#include "Driver.h"

Driver::Driver(const string& name, const int& experience, Car* car)
	: name(name), experience(experience), car(car)
{
	//setName(name);
	//setExperinece(expereince);
	//setCar(car);
}

void Driver::print() const
{
	cout << "Driver name : " << name << endl;
	cout << "Driver experience : " << experience << endl;
	if (car != nullptr)
	{
		car->print();
	}
	else
	{
		cout << "Driver does not car\n";
	}
}

void Driver::setCar(Car* car)// метод для зміни авто, яким керує  Водій
{
	this->car = car; // 
}

Driver::~Driver()
{
	cout << "~~~~~Destructor for driver " << name << " done\n";
}
