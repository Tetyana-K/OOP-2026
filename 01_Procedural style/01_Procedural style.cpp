// 01_Procedural style.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

// data,  code 
//
struct Car // зразок для створення обєктів типу Car
{
	//private: // закриті для зовн світу
	//public: //відкриті для зовн світу
	string brand = "Nobrand";// поля, дані-елементи
	string  color;
public:
	int year = 2000;
};


// global  function gets car as parameter

void print(const Car& car) // глобальна функція
{
	cout << car.brand << "\t" << car.color << "\t" << car.year << endl;
}

const Car audi{ "Audi", "White" }; // object (instance) of struct Car, глобальна змінна (у області  глобальних, статичних даних)
int main()// client code
{
	cout << "PROCEDURAL STYLE\n"; // types, functions
	print(audi);

	Car bmw{ "BMW", "Silver", 2022 }; // object of struct Car (створена на стеку, локальна змінна)
	print(bmw);

	//print(bmw);
	//Car* p = new Car {"Toyota", "Black", 2021};
	auto p = new Car{ "Toyota", "Black", 2021 }; // auto - автоматичне визначення типу
	cout << p->brand << endl;

	delete p; // звільняється дин память
	p = nullptr;

	auto value = 3489;
	cout << "type of value " << value << " = " << typeid(value).name() << endl;
}

