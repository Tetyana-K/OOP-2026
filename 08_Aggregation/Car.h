#pragma once
#include <string>
#include <iostream>
using namespace std;
class Car
{
public:
	Car(const string& brand = "Noname", int year = 2020);
	void print() const;
	
private:
	string brand;
	//char* bramnd = new char[100];
	int year;
};

