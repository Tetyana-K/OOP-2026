#pragma once
#include "IShapes.h"
class Circle : public IShape, public IPrint
{
public:
	double area() const override ;
	Circle(const  double& radius = 1)
		:radius(radius)
	{}
private:
	double radius;
	virtual double length() const override;
	virtual void show() const override;

};

class Square : public IShape, public IPrint,  public IDraw
{
public:
	Square(const  double& side = 1)
		:side(side)
	{}
	
	double area() const override;
	virtual double length() const override;
	
	virtual void IPrint::show() const override;
	virtual void IDraw::show() const override;

private:
	double side;


};
