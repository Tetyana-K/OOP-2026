// 01_Procedural style.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

// data,  code 
struct Car // зразок для створення обєктів типу Car
{
//private:
//public: //відкриті для зовн світу
    string brand;// поля, дані-елементи
    string  color;
    int year = 2000;
   
};
// global  function gets car as parameter
void print(const Car & car) // + 
{
    cout << car.brand << "\t" << car.color << "\t" << car.year << endl;
}

int main()// client code
{
  

    cout << "PROCEDURAL STYLE\n";
    Car audi { "Audi", "White"}; // object (instance) of struct Car
    print(audi);
    
    Car bmw{ "BMW", "Silver", 2022 }; // object of struct Car
    print(bmw);

    //Car* p = new Car {"Toyota", "Black", 2021};
    auto p = new Car {"Toyota", "Black", 2021};
    cout << p->brand << endl;
    delete p;
    p = nullptr;
}

