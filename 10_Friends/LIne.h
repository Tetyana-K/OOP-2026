#pragma once
#include "Point.h"
class Point2D;
class Line
{
public:
	Line(double xLeft, double yLeft, double xRight, double yRight);
	//Line(const Point2D& left, const Point2D& right);
	void print() const;

private:
	class Point2D left, right; // 
};

