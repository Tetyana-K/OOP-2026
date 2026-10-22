#pragma once
#include "Transport.h"
// при protected успадкуванні 
// private ---> невидимий напряму
// protected --> protected
// public --> protected

// при private успадкуванні 
// private ---> невидимий напряму
// protected --> private
// public --> pivate
class Ship
	: protected  Transport // public ---> protected
{
public:
	Ship(const string& brand, int year);
	void move() const; // пишемо новий move()
	void info() const; // якщо не  переписуємо info(), то буде братися реалізація із батьківського класу
	~Ship();
private:

};
// Ship  успадкував метод increaseSpeed(), і він став protected,  тобто зовн світ НЕ БАЧИТЬ

