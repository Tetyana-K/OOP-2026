#include <iostream>
using std::cout;
using std::endl;
#include "Point.h"
#include "LIne.h"

Line::Line(double xLeft, double yLeft, double xRight, double yRight)
	: left(xLeft, yLeft),  // викликаємо конструктор з  2 параметрами для точки left
	right(xRight, yRight)// конструктор з  2 параметрами для точки right
{
}
void Line::print() const
{
	cout << "_____LINE_____\n";
	cout << "Left point : ";
	left.print();
	cout << "x = " <<left.x << ", y = " << left.y << endl;
	cout << "Right point : ";
	right.print();
}
