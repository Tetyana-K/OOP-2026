#pragma once
//class Line; // попереднє оголошення класу
#include "LIne.h"
class Point2D
{
private:
	double x, y;
public:
	Point2D(double x = 0, double y = 0); // 3 і одному
	void print()const;

	friend double distBtwPoints(const Point2D& , const Point2D& ); // оголосили другом класу Point2D глобальну функцію
	//friend class Line; // оголосили другом класу Point2D клас Line
	
	friend void Line::print() const;
};

