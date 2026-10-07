// 01_Procedural style.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

// Incapsulation
class Car // in classes by default  all members PRIVATE, in structures -  PUBLIC
{

public:
	//void print() const// метод не буде змінювати поля структури-класу 
	//{
	//	cout << brand << "\t" << this->color << "\t" << year << endl;
	//}
	void print()const; // декларація (прототип) методу, тоді треба реалізувати за межами класу
	void input()
	{
		cout << "\t\tEnter car brand : ";
		cin >> brand;

		cout << "\t\tEnter car color : ";
		cin >> this->color; // this = вказівник на поточний обєкт (на обєкт для  якого викликано метод)
	}
	/*void setBrand(const string& newBrand) {
		if (newBrand != "")
			brand = newBrand;
	}*/

	Car& setBrand(const string& newBrand) // setter, mutator = метод для ЗМІНИ деякого поля(полів) класу
	{
		if (newBrand != "") // !newBrand.empty() - перевірка чи дане підходить (рядок не пустий)
			brand = newBrand; //тоді змінюємо поле бренду
		return *this;// this- pointer    - повертаємо посилання на поточну машинку, бренд якої зараз змінювали
	}

	const string& getBrand() const // getter (accessor) = метод, який повертає  значення певного поля
	{
		return brand;
	}
	Car& setYear(int year) // setter for year
	{
		if (year >= 1900 && year <= 2023)
			this->year = year; // поле = формальний параметр
		return *this;// повертаємо за посиланням ЦЕЙ об'єкт, надалі можна продовжити зміну стану об'єкту 
	}
	//void setYear(int year)// setter for year, mutator
	//{
	//	if (year >= 1900 and year <= 2026)
	//	{
	//		this->year = year; // поле = формальний параметр
	//	}
	//}

private: //захист даних  від неконтрольованого використання зовн. світом
	string brand = "Nobrand";
	string color = "Nocolor";
	int year = 2000;
public:
	int getYear() const // getter для поля year
	{
		return year;
	}
	Car(const string& brand, int year, const string& color) // - це контструктор з трьома парамтрами- викликається автоматично при створенні обєкта
	{
		setBrand(brand);
		setYear(year);
		if (!color.empty())
			this->color = color;
	}
	Car() // конструктор без параметрів, по замовчуванню, default, void- конструктор
	{
		//color = "White";
	}
	//Car() = default; // те саме, як пустий дефолтний к-р

	~Car() // деструктор, спрацює при вилученні об'єкта автоматично
	{
		cout << "~~~~~~~~~~~~~~ Dtor  for car '" << brand << "'\t(" << year << ") year" << endl;
	}
};


void Car::print() const//const -  метод не буде змінювати поля структури-класу 
{
	cout << brand << "\t" << this->color << "\t" << year << endl;
}

int main()
{

	cout << "OOP STYLE\n";

	Car audi; // object of class Car
	//cout << audi.color << endl; // error -because private
	audi.print();
	cout << "Year : " << audi.getYear() << endl;

	//audi.setYear(2026);
	//audi.brand = "Audi";

	// виклик сетерів послідовним ланцюжком, можливо, якщо сетери повертають посилання на поточне авто (Car&)
	audi.setBrand("Audi").setYear(2026).setYear(2024); // 2024
	//audi.setBrand("Audi");
	//audi.setYear(2020);
	//audi.setYear(200);

	audi.print(); // this = address of audi 

	Car bmw; // object of struct Car
	bmw.setBrand("BMW");
	bmw.setYear(2025);
	bmw.print(); // this = address of bmw 

	Car bmw2; // object of struct Car
	bmw2.setBrand("BMW");
	bmw2.setYear(2019);

	bmw2.print(); // this = address of bmw 

	// масив із вказівників на об'єкти машин
	Car* salon[] = {/*&audi,*/ &bmw, &bmw2 };
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

	Car* toyota = new Car("Toyota", 2022, "blue");
	toyota->print();
	delete toyota;

	//Car mers("Mers", 2023); // error - бо немає к-ра з 2 параметрами
	//Car mists("Mitshubisi"); // error - бо немає к-ра з 1 параметрами
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


