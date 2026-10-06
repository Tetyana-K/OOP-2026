// 01_Procedural style.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

// Incapsulation
class Car // in classes by default  all members PRIVATE, in structures -  PUBLIC
{

public:
	void print() const// метод не буде змінювати поля структури-класу 
	{
		cout << brand << "\t" << this->color << "\t" << year << endl;
	}
	void input()
	{
		cout << "\t\tEnter car brand : ";
		cin >> brand;

		cout << "\t\tEnter car color : ";
		cin >> this->color; // this = вказівник на поточний обєкт (на обєкт для  якого викликано метод)
	}
	//void setBrand(const string& newBrand) {if (newBrand != "") 	brand = newBrand;}

	Car& setBrand(const string& newBrand) // setter, mutator = метод для ЗМІНИ деякого поля(полів) класу
	{
		if (newBrand != "") // !newBrand.empty() - перевірка чи дане підходить (рядок не пустий)
			brand = newBrand; //тоді змінюємо поле бренду
		return *this;// this- pointer   
	}
	const string& getBrand() const // getter (accessor) = метод, який повертає  значення певного поля
	{
		return brand;
	}
	Car& setYear(int year) // setter for year
	{
		if(year >= 1900 and year <=2023)
			this->year = year; // поле = формальний параметр
		return *this;// повертаємо за посиланням ЦЕЙ об'єкт, надалі можна продовжити зміну стану об'єкту 
	}
	int getYear() const // getter
	{
		return year;
	}
private: //захист даних  від неконтрольованого використання зовн. світом
	string brand ="Nobrand";
	string color ="Nocolor";
	int year = 2000;
	

};


int main()
{
	
	cout << "OOP STYLE\n";
	Car audi; // object of class Car
	audi.print();
	cout << "Year : " << audi.getYear() << endl;
	//audi.brand = "Audi";
	audi.setBrand("Audi").setYear(2022).setYear(2017); // 2017
	//audi.setBrand("Audi");
	//audi.setYear(2020);
	//audi.setYear(200);

	audi.print(); // this = address of audi 

	Car bmw; // object of struct Car
	bmw.setBrand("BMW");
	bmw.setYear(2022);
	bmw.print(); // this = address of bmw 

	Car bmw2; // object of struct Car
	bmw2.setBrand("BMW");
	bmw2.setYear(2019);
	
	bmw2.print(); // this = address of bmw 

	Car* salon[] = { &audi, &bmw, &bmw2 };
	int count = 0;
	cout << "\n_________List of BMW cars _________________\n";
	for (Car* c : salon)
	{
		if (c->getBrand() == "BMW")
		{
			++count;
			c->print();
			
		}
	}
	cout << "\nWe found " << count << " cars of brand 'BMW'\n";
}

// Описати структуру Прямокутник(ширина та висота). Визначити методи (функції  всередині структури) для 
// виведення даних прямокутника
// введення даних прямокутника
// обчислення площі  прямокутника (повертати результат)
// перевірити роботу структури, створюючи обєкт(и) прямокутника(ів)

// Переробити  структуру Прямокутник на клас (поля double занести у приватну частину).
// Визначити гетери те сетери для кожної сторони ( допускаються тільки додатні)
// Перевірити роботу класу 
// * Створити два об'єкти Прямокутника,   знайти прямокутник з  більшою площею, або вивести інформацію про однакові площі прямокутників


