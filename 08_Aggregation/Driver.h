#pragma once
#include "Car.h"
class Driver // демо відношення між класами АСОЦІАЦІЯ
{
public:
	Driver(const string& name = "Noname", const int& experience = 1, Car* car = nullptr);
	void print()const;
	void setCar(Car* car);
private:
	string name;
	int experience;
	//Car& car; -- так можна, але тоді Водій буде постійно пов'язаний з одним авто, не зможемо потім призначити інше авто
	Car* car; // так буде більш гнучко
};

