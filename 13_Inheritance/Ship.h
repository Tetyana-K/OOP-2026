#pragma once
#include "Transport.h"
class Ship
	: protected Transport // public ---> protected
{
public:
	Ship(const string& brand, int year);
	void move() const; // пишемо новий move()
	//void info() const; // якщо не  переписуємо info(), то буде братися реалізація із батьківського класу
	~Ship();
private:

};

