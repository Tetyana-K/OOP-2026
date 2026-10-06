// 08_Aggregation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include "Car.h"
#include "Driver.h"
int main()
{
	Car bmw("BMW", 2022);
	bmw.print();
	cout << endl;

	Car ford("Ford", 2020);
	ford.print();
	cout << endl;
	{
		Driver driver("Oleh", 5, &ford); // створили об'єкт Водія і повязали його з авто ford
		driver.print();
		cout << endl;

		driver.setCar(&bmw);
		driver.print();
	}

}

