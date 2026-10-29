// 23_class template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// FixedArray template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
#include "Array.h"

template <typename T> //  шаблон функції
void printArray(const T arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "\t" << arr[i];
	}
	cout << endl;
}
int main()
{
	/*int arr[]{ 10, 20, 30 };
	string words[]{ "Ukraine" , "Rivne", "Lviv", "Zdolbuniv"};

	printArray(arr, size(arr));
	printArray(words, size(words));*/



	FArray<int, 5> a(2);
	// 1) компілятор на основі шаблону класу  FArray створив конкретний клас  class FArrayInt5 { private: int array[5];   }
	// 2) створення обєкта a, працює конструктор з 1-м параметром (передаємо 2), тобто масив буде 2 2 2 2 2
	a.print();
	//a.array[0] = 111;
	try {
		a[0] = 111;// працює перевнтажений оператор індексування
		a[2] = 333;// працює перевнтажений оператор індексування
		a[5] = 888; // полетить виняток
		//a.array[2] = 255;
		a.print();
	}
	catch (const out_of_range & ex)
	{
		cout << "Error : " << ex.what() << endl;
		a.print();

	}
	cout << a << endl;
	//for (size_t i = 0; i < 5; i++)
	//{
	//	//cout <<"#" << i  << "\t"<< a.array[i] << endl;
	//}

	FArray<string, 4> s("C++");// class FArrayS { private : string array[4];   }
	//s.array[0] = "C++"; // ok якщо поле array відкрите
	//s.array[1] = "UML";
	s[1] = "UML";
	s[2] = "Design patterns";
	//s.array[3] = "C#";
	cout << endl;
	s.print();

	for (size_t i = 0; i < 4; i++)
	{
		cout << "#" << i << "\t" << s[i] << endl;
	}
	FArray <double> d(3.14); // class FArrayD{      double array[10];} 10 = значення параметра size  за замовчуванням
	d.print();

	FArray <> f(-1); // class FArrayI10{      int array[10];} T = int за засовчуванням, 10 = значення параметра size  за замовчуванням
	f.print();

	cout << s;
}

