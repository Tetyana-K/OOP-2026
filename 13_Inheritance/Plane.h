#pragma once
#include "Transport.h"
// public успадкування
//  base class --- child class
// private --->  недоступне
// protected ---> protected
// public ---> public
class Plane :
    public Transport // успадкувалися від  класу Транспорт (тобто клас має поля brand, year)
{
public:
    Plane(const string &  brand = "No brand", int year = 2000, int height = 5000);
   void info() const override; // overriding
   void move()const; // пишемо тут новий метод (з  таким самим прототип) = новий метод перекриє  старий (з  базового класу ), hiding = overlapping
    ~Plane();
private:
    int height; // висота польоту літака =  особливе поле для класу Літак
};
// Plane успадкував метод increaseSpeed(), і він залишився public
