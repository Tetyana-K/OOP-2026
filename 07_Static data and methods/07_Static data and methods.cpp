// 07_Static data and methods.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include "Employee.h"
void demo(Employee e)
{
    cout << "\t\tIn func demo()\n";
    e.print();
    cout << "\t\tEnd of  func demo()\n";
}
int main()
{
    Employee ann("Ann", 14789);
    demo(ann);

    string name = "Petro";
    demo(name); // компілятор (якщо к-р без explicit) намагається допомогти, і шукає конструктор з  1 параметром типу string
    
    demo({ "Olena", 10000 });// компілятор (якщо к-р без explicit) намагається допомогти, і шукає конструктор з  2-ма параметрами типу string, int

    cout << "\tArray of employees\n";

    Employee emps[2] = { {  "Ivan", 12000}, {"Dmytro", 15000} };
    for (auto& e : emps)
    {
        e.print();
    }
    
    // string "Petro"------> Employee "Petro" 7800 id = 2

    //cout << "Counter  = " << Employee::getCount() << endl;//Employee::counter << endl;
    //cout << "Company  = " << Employee::getCompany() << endl;

    //Employee::setCompany("Cool Programmers");
    //cout << "Company  = " << Employee::getCompany() << endl;
    //Employee emp("Olena", 18'000);
    //emp.print();
    ////emp.simplePrint(emp); // bad style
    //Employee::simplePrint(emp); // виклик static методу

    ////cout << "Bad example of access for static  : " << emp.getCount() << endl;
    //cout << "Counter  = " << Employee::getCount() << endl;//Employee::counter << endl;
    //
    //Employee team[4] = {
    //    Employee{"Pavlo", 22'000},
    //    {"Nataliya", 15'900},
    //    {"Oleh"}
    //};
    //cout << "Counter  = " << Employee::getCount() << endl;//Employee::counter << endl;
    //cout << "\n\nTeam\n";
    //for (auto& e : team)
    //{
    //    e.print();
    //}

}


