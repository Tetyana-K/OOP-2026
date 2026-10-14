// 06_Copy  ctor (with dynamic).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Pupil.h"
int main()
{
	std::cout << "____Copy  ctor demo for class with dynamic fields____\n";
	Pupil pupil("Oleh", 9);// к-р має третій параметр позамовчуванню із значенням 3, тому масив marks створюється з 3-х оцінок
	pupil.setMark(0, 11);
	pupil.setMark(1, 12);
	pupil.print();
	cout << endl;

	Pupil clone = pupil;
	clone.print();

	Pupil pupil2;
	pupil2.print();

	pupil2.~Pupil();
}

