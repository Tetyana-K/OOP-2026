#pragma once
#include "IShapes.h"

// клас оеалізує інтерфейси IShape, IPrint
class Circle : public IShape, public IPrint
{
public:
	double area() const override ;
	explicit Circle(const  double& radius = 1)
		: radius(radius)
	{}
	virtual double length() const override;
	virtual void show() const override;
	
	const double getRadius() const { return radius; } // звичайний метод, гетер
	void setRadius(double radius) // звичайний метод, сетер
	{
		if (radius > 0)
			this->radius = radius;
	}
private:
	double radius;

};
 // тут буде конфлікт при реалізації інтерфейсів - IPrint та IDraw містять метод show () з однаковою сигнатурою
class Square : public IShape, public IPrint, public IDraw
{
public:
	explicit Square(const  double& side = 1)
		:side(side)
	{}
	
	double area() const override;
	virtual double length() const override;
	
	//virtual void show() const override; // одна відкита реалізаціяя на ОБИДВА інтерфейси
	
	virtual void IPrint::show() const override; // хочемо різні реалізації  show() для інтерфейсів IPrint, IShow
	virtual void IDraw::show() const override;

private:
	double side;
};
