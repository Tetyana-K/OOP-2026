// 23_class template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// FixedArray template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
#include "Array.h"
int main()
{
	FArray<int, 5> a(2);
	// 1) компілятор на основі шаблону класу  FArray створив конкретний клас  class FArrayInt5 { private: int array[5];   }
	// 2) створення обєкта, працює конструктор з 1-м параметром
	
	//a.array[0] = 111;
	try {
		a[0] = 111;// працює перевнтажений оператор індексування
		a[5] = 888; // полетить виняток
		//a.array[2] = 255;
		a.print();
	}
	catch (const out_of_range & ex)
	{
		cout << "Error : " << ex.what() << endl;
		a.print();

	}
	for (size_t i = 0; i < 5; i++)
	{
		//cout <<"#" << i  << "\t"<< a.array[i] << endl;
	}

	FArray<string, 4> s("C++");// class FArrayS { private : string array[4];   }
	//s.array[0] = "C++";
	//s.array[1] = "UML";
	s[1] = "UML";
	//s.array[2] = "Design patterns";
	//s.array[3] = "C#";
	cout << endl;
	s.print();

	for (size_t i = 0; i < 4; i++)
	{
		//cout << "#" << i << "\t" << s.array[i] << endl;
	}
	FArray <double> d(3.14); // class FArrayD{      double array[10];} 10 = значення параметра size  за замовчуванням
	d.print();

	FArray <> f(-1); // class FArrayI10{      int array[10];} T = int за засовчуванням, 10 = значення параметра size  за замовчуванням
	f.print();

	cout << s;
}

