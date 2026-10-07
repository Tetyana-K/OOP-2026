// 01_Procedural style.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

// data + code (methods, function -members)
struct Car
{
//private:
//public:
	string brand;// поле, дане-елемент
	string  color;
	int year = 2000;
//public:
	void print() const// функція-елемент структури, const = метод не буде змінювати поля структури-класу 
		// у функцію неявно приходить вказівник this = вказівник на обєкт, для якого викликається метод
	{
		cout << brand << "\t" << this->color << "\t" << year << endl;
		//cout << "This = " << this << endl;
	}
	void input()//  функція-елемент структури, метод
	{
		cout << "\t\tEnter car brand : ";
		cin >> brand;

		cout << "\t\tEnter car color : ";
		cin >> this->color; // this = вказівник на поточний обєкт (на обєкт для  якого викликано метод)
		
		cout << "\t\tEnter car year : ";
		cin >> this->year; // this = вказівник на поточний обєкт (на обєкт для  якого викликано метод)
	}
};
//void print()
//{
//	cout << "Hello\n";
//}

int main()
{
	//print(); // виклик глобальної функції print()
	
	cout << "PROCEDURAL STYLE\n";
	
	Car audi{ "Audi", "White", 2020 }; // object of struct Car, створюється об'єкт( екземпляр) структури Car
	
	cout << "Address of audi = " << &audi << endl;
	audi.print(); // вказівник this = address of audi 

	Car bmw{ "BMW", "Silver", 2022 }; // object of struct Car
	cout << "Address of bmw = " << &bmw << endl;
	bmw.print(); // this = address of bmw 

	Car car;
	car.input();
	car.print();
	

}

// Описати структуру Прямокутник(ширина та висота). Визначити методи (функції  всередині структури) для 
// виведення даних прямокутника
// введення даних прямокутника
// обчислення площі  прямокутника (повертати результат)
// перевірити роботу структури, створюючи обєкт(и) прямокутника(ів)
