#pragma once
#include <iostream>
using namespace std;
class Point
{
public:
	double getX() const { return x; } // якщо метод реалізовний у тілі класу, то компілятор намагається зробити його inline
	double getY()const ;// прототип методу

	void setX(const double& x);
	void setY(const double& y);

	void print() const;
	// конструктор = метод викликається при створенні обєкта (1 раз), служить для початкової ініціалізації полів класу
	Point() : x(0), y(0)// default  ctor
	{
		//x = y = 0;
		cout << ">>>>>>>>Default Ctor x = " << x << " y = " << y << endl;// демо повідомлення 

	}
	Point(const double& x, const double& y); // к-р з 2 параметрами

	Point(const double& x) // к-р з 1 параметром
		:x(x), y(0)
	{
		cout << ">>>>>>>>Ctor with 1 param x = " << x << " y = " << y << endl;

	}
	~Point() //деструктор, метод який викликається при вилученні об'єкта, зараз демо-деструктор
	{
		cout << "~~~~~~~~ Dtor for point  x = " << x << " y = " << y << endl;
	}
private:
	double x;
	double y; // координати точки на площині

};

inline double Point::getY() const // так теж  можна реалізувати вбудований (inline) метод класу
{
	return y;
}

