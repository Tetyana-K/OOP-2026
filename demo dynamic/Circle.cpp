#include "Circle.h"

void Circle::setRadius(double radius) // реалізація методу за межами опису класу
{
	if (radius > 0)
	{
		this->radius = radius;
	}
}

double Circle::getRadius() const
{
	return radius;
}
