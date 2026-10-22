// Inheritance_Intro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Person.h"
#include "Developer.h"
using std::cout;
using std::endl;

void demo(Human human) // метод приймає КОПІЮ оригінала  
{
    cout << "-------------Demo ()----\n";
    human.eat();
    human.learn();
    cout << endl;
}

void demoRef(Human& human) // метод приймає  посилання на оригінал  
{
    cout << "-------------Demo Ref ()----\n";
    human.walk();
    human.learn();
    //human.coding() // coding()  видначено у класу Developer, y Human  цього методу немає
    cout << endl;
}
int main()
{
    Human olena("Olena", 20);
    olena.walk(); 
    olena.learn(); 
    olena.learn(2); // приклад статичного поліморфізму - перевантажені методи (операції)
    // Статичний полімофізм - компілятор розуміє, який з методів викликати
    // Раннє зв'язування - раннє звязування (на етапі компіляції) виклику методу з його реалізацією
    std::cout << endl;
    //olena.coding(); -- це метод з похідного типу
    demo(olena);

    Developer ivan("Ivan", 28, "Softserve");
    
    ivan.eat();
    ivan.learn();
    //ivan.learn(4);
    ivan.walk();
    ivan.coding();

    // при успадкуванні обєкт похідного типу може підставлятися у точки коду, де очікується обєкт базового типу
    demo(ivan);// обєкт ivan копіюється у параметр функції human (буде працювати конструктор копії)
    
    demoRef(ivan);// обєкт ivan передається у функцію  за посиланням (копія не створюється)
}

