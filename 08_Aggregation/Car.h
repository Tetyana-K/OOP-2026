#pragma once
#include <string>
#include <iostream>
using namespace std;
class Car
{
public:
	Car(const string& brand = "Noname", int year = 2020);  // Car car;
	void print() const;
	~Car();
private:
	string brand;
	//char* brand = new char[100];
	int year;
};

