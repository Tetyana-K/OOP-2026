// demo zao.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

void printMarks(string name, int marks[], int size);
int main()
{
	string name = "Oleh";
    int marks[5] = { 10,12,7, 8, 9 };
    printMarks(name, marks, 5);
}

void printMarks(string name, int marks[], int size)
{
	cout << name << "'s marks :";
	for (size_t i = 0; i < size; i++)
	{
		cout << "\t" << marks[i];
	}
}
