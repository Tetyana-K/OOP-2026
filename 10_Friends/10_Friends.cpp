// 10_Friends.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
// friend - порушує  інкапсуляцію, маючи ПРЯМИЙ доступ до приватної або захищеної частини класу
// Другом класу може бути
// 1) глобальна функція  void func(MyClass& obj ) {...MyClass& tmp;...}
// 2) функція-елемент якогось класу  void Other::func(MyClass& obj ) {...MyClass& tmp;...}
// 3) інший клас (усі функції-елементи якогось класу)  void Other::func(MyClass& obj ) {...MyClass& tmp;...}
// Друга оголошує сам клас friend
// Друзі не симетричні
#include <iostream>
using std::cout;
#include "Point.h"
#include "Line.h"

double distBtwPoints(const Point2D& p1, const Point2D& p2)
{
    return sqrt( pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main()
{
    Point2D a(1.2, -3.4);
    Point2D b(0, 1);
    a.print();
    b.print();
    cout << "Global functios is friend of Point2D\n";
    cout << "Distance : " << distBtwPoints(a, b) << endl;
    
    cout << "\nWhole class Line is  friend of Point2D\n";
    Line line(1, 2, 3, 4);
    line.print();
}

