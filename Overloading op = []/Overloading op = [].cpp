// Overloading op = [].cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Pupil.h"
void fun(int val, string  text)
{
	cout << text << " :: " << val  << endl;
}
int main()
{


	//fun(2, "Value");// fun()

	Pupil olena("Olena", 10, 7);
	olena.setMark(0, 11);
	olena.setMark(1, 12);
	
	olena[2] = 9;// посилання на оцінку # 2 = 9, запишемо у елемент масиву #2 обєкта pupil число 9
	olena[3] = 100;
	olena.print();
	
	//pupil[-1] = 12; // error --- exit(1)
	
	cout << "\nFirst mark " << olena[0] << endl; //  pupil[0]  -  виклик операції індексування
	cout << "Second mark " << olena[1] << endl; //  pupil[0]  -  виклик операції індексування
	cout << "Third mark " << olena[2] << endl; //  pupil[0]  -  виклик операції індексування
	//cout << "10th mark " << pupil[10] << endl; //  pupil[0]  -  виклик операції індексування
	cout << endl;

	Pupil anton("Anton", 11, 3);
	anton[0] = 8;
	anton[1] = 9;
	anton[2] = 12;
	anton.print();

	cout << "\nPupil tmp = olena ----  works COPY CTOR\n";
	Pupil tmp = olena;// copy ctor !!! 
	tmp.print();

	cout << "\ntmp = anton ----  works OPERATOR =\n";
	tmp = anton; // operator = потрібно програмувати НАМ, якщо клас має динамічні 
	tmp.print();

	cout << "\nOperator call function (string, int)\n";
	tmp("Andrii", 10);
	tmp.print();
	
	cout << "Bye!\n";
}

