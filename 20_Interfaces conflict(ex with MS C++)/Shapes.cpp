#define _USE_MATH_DEFINES
#include <cmath>
#include<iostream>
#include "Shapes.h"


double Circle::area() const
{
    return M_PI * radius *  radius;
}

double Circle::length() const
{
    return 2 * M_PI * radius;
}

void Circle::show() const
{
    std::cout << "Circle with  radius : " << radius << std::endl;
}

double Square::area() const
{
    return side *  side;
}

double Square::length() const
{
    return 4 * side;
}

void Square::IPrint::show() const
{
    std::cout << "Square with  side : " << side << std::endl;
}

void Square::IDraw::show() const
{
    char  symbol = '*';
    for (size_t i = 0; i < side; i++)
    {
        for (size_t j = 0; j < side; j++)
        {
            std::cout << symbol;
        }
        std::cout << std::endl;
    }
}