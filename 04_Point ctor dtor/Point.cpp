#include "Point.h"
#include <iostream>
using namespace std;
void Point::print() const
{
	cout << "(" << x << ", " << y << ")\n";
}
void Point::setX(const double& x)
{
	this->x = x;
}
void Point::setY(const double& y)
{
	this->y = y;
}
//Point::Point(const double& x, const double& y)
//{
//	setX(x); // ми викликали сетери для полів (це часто зручно, уникаємо дублювання)
//	setY(y);
//}

// при реалізації к-ра можна скористатися СПИСКОМ ІНІЦІАЛІЗАЦІЇ ПОЛІВ
Point::Point(const double& x, const double& y)
	: x(x), y(y) // : назваПоля(значення яке ініціалізуємо у поле), назваПоля2(значення2 чи вираз2)
{
	cout << ">>>>>>>Ctor with 2 param x = " << x << " y = " << y << endl;

	// this->x = x;
	// this->y = y
}