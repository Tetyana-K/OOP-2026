#include <iostream>
using std::cout;
using std::endl;
#include "Point.h"


Point2D::Point2D(double x, double y)
	: x(x), y(y)
{
}
void Point2D::print() const
{
	cout << "(" << x << ", " << y << ")\n";
}
