// 06_Copy  ctor (with dynamic).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Pupil.h"
int main()
{
    std::cout << "____Copy  ctor demo for class with dynamic fields____\n";
    Pupil pupil("Oleh", 9);
    pupil.setMark(0, 11);
    pupil.setMark(1, 12);
    pupil.print();
    cout << endl;

    Pupil clone = pupil;
    clone.print();
}

