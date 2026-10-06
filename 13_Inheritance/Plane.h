#pragma once
#include "Transport.h"
class Plane :
    public Transport // успадкувалися від  класу Транспорт (тобто клас має поля brand, year)
{
public:
    Plane(const string &  brand = "No brand", int year = 2000, int height = 5000);
    void info() const override; // hiding
   void move()const; // пишемо тут новий метод (з  таким самим прототип) = новий метод перекриє  старий (з  базового класу ), hiding = overlapping
    ~Plane();
private:
    int height; // висота польоту літака =  особливе поле для класу Літак
};

