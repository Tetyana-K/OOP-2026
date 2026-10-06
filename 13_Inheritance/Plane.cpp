#include "Plane.h"

// конструктор похідного типу викликає конструктор базового типу 
Plane::Plane(const string& brand, int year, int height) // 
	:  height(height),
	Transport(brand, year) // явно викликали конструктор базового класу Транспорт 
{
	//setHeight (height)
	cout << "\t\tCtor Plane '" << getBrand() << "' year " << year << endl;
}

void Plane::info() const
{
	//Transport::info(); // виклик методу info() із базового класу Transport
	cout << "Plane '" << /*brand<<*/ getBrand() << "'\tYear : " // brand у базовому класі приватне, тому прямого доступу ту немає
		<< year << "\theight : " << height <<endl; // year - доступ є через те що поле у базовому класі  protected
}

void Plane::move() const
{
	//cout << "Plane '" << brand ---  error,  у дочіпньому класі  не видно, бо приавтний у базовому класі
	cout << "Plane '" << getBrand() << "' can fly\n";
}

Plane::~Plane() // дестроуктор похідного типу при завершенні роботи неявно викличе деструктор базового типу
{
	cout << "\t\tDtor plane '" << getBrand() << "'\n";
}
