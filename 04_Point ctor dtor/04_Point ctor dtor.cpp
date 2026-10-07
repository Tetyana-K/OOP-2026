// 04_Point ctor dtor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include "Point.h"
#include "Point3D.h"
// Конструктор -  метод викликається 1 раз при створенні об'єкта, служить для ініціалізації полів класу
// Якщо клас(чи структура) не містить жодного к-ра, то компілятор НАДАЄ к-р по замовчуванню
// Якщо у класі є  хоч один к-р з  параметрами, то ми к-р по замовчуванню  пишемо САМІ 
// * Конструктор повинен називатися іменем класу(структури), не повинен повертати результат 
// Конструктор може мати параметри
// Клас може мати довільне число конструкторів

// Деструктор - метод працює при знищенні обєкта, тут прийнято очищати ресурси, які займає  об'єкт (вилучають динамічні поля, закриття файла)
// Назва деструктора   ~назва класу                            //a = 1000  ~a  0111
// Клас може містити тільки ОДИН деструктор
// Деструктор не повертає  результат, не має параметрів

const Point global(1, -1);// ctor with  2 params, зробили const, бо рекомендують глобальні об'єкти без зміни стану робити const

void demo()
{
	Point local(3.3, -4.4); //ctor with 2 params
	local.print();
	// dtor
}
int main()
{
	cout << "Demo  ctors\n";

	demo();

	global.print();

	return 0;
	Point a; // тут працює к-р по замовчуванню, default constructor (ctor), void ctor, ctor without  parameters (parameterless)
	a.setX(3.4);
	a.print();// 3.4 0
	cout << endl;

	{
		Point b(10.8, 1.2); // тут працює к-р з  2 параметрами
		b.print();
		// b -  локальний об'єкт, закривається блок, тобто буде знищення b ---> спрацює деструктор 
	}
	cout << endl;
	Point c(7.7); // к-р з  1 параметром
	c.print();

	// Point d(10, 2, 3); // тут помилка компіляції, бо клас не містить к-ра з  3-ма параметрами
	Point* f = new Point(88, 100);// ctor with 2 parameters
	f->print();
	delete f; // вилучаємо дин об'єкт, тобто спрацює деструктор

	cout << "\nArray of default points\n";
	Point arr[3];// створюється масив 3-х обєктів точок, для кожної  з точоко викликати дефолтний к-р
	for (auto p : arr)// range for
	{
		p.print();
	}
	cout << endl;

	Point arr2[2]{ Point(4,4), Point(-5, -5) };
	for (auto p : arr2)
	{
		p.print();
	}
	cout << endl;
	cout << "____Point 3D______\n";

	Point3D p3;
	p3.print();
	Point3D p4(1, -2, 111);
	p4.print();

}


