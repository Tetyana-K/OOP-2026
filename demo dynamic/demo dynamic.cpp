// demo dynamic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include "Circle.h"
int main()
{
    Circle circle; // default ctor
    circle.setRadius(-10);
    cout << circle.getRadius() << endl;


    //String obj("Test"); // len = 5
    //int len = 80;
    //
    //char* str = new char[len] {}; // \0\0\0\0\0
    //cout << "!!!!!!!!!!!!!!!String : '" << str << "'\n";

    //strcpy_s(str, len, "Test line");
    //cout << "String : '" << str << "'\n";

    //strcat_s(str, len, "+Add line");
    //cout << "String : '" << str << "'\n";

    //cout << "\nEnter string: ";
    //char  symbol;
    //cin.get( symbol);
    //cin.get(symbol);
    ////cin.getline(str, len);
    //cout << "String : '" << str << "'\n";
    //
    //char* tmp = new char[len] {};
    ////cin.getline(tmp, len); // ???
    //cout << "String temp : '" << tmp << "'\n";
    //delete[] str;
    //str = nullptr;
}

