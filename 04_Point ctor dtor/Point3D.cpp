#include <iostream>
#include "Point3D.h"


//Point3D::Point3D(int x, int y, int z)
//{
//	this->x = x;// this->x - поле класу, x - формальний параметр конструткора
//	this->y = y;
//	this->z = z;
//}

Point3D::Point3D(int x, int y, int z)
	: x(x), y(y), z(z) // список ініціалізації конструктора, тут можемо виконувати нескладін ініціалізації полів (присвоєння)
{
	//this->x = x;
	//this->y = y;
	//this->z = z;
}

void Point3D::print() const
{
	std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}
