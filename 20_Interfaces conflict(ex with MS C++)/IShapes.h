#pragma once
__interface IShape
{
	double area() const; // неявно абстрактний та відкритий
	double length() const;
};
__interface IDraw
{
	void  show() const;
};
__interface IPrint
{
	void show() const;
};
