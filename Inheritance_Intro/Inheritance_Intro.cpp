// Inheritance_Intro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Person.h"
#include "Developer.h"
using std::cout;
using std::endl;
int main()
{
    Human olena("Olena", 20);
    olena.walk();
    olena.learn();
    std::cout << endl;
    //olena.coding(); -- це метод з похідного типу

    Developer ivan("Ivan", 28, "Softserve");
    
    ivan.eat();
    ivan.learn();
    ivan.walk();
    ivan.coding();

}

