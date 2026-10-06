// 04_vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <array>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;
template <typename T>
void print(const  T& container) //буде працювати для  масиву фіксованого розміру, вектора 
{
	for (const auto& el : container)
	{
		cout << el << "\t";
	}
	cout << endl;
}

bool isNegative(int value)
{
	return value < 0;
}
bool isEven(int value)
{
	return value % 2 == 0;
}
int mult2(int value) // for transform
{
	return 2 * value;
}
int sqr(int value) // we plan to use it for transform
{
	return value * value;
}
int main()
{
	//int arr[]{12, 34, -45, 789, -12, -137, 12};
	//sort(arr, arr + size(arr)); // впорядкування масиву за доп.  алгоритму (шабл функція) за зростанням
	//cout << "Sorted by  acs\n";
	///*for (auto& el : arr)
	//{
	//	cout << "\t" << el;
	//}
	//cout << endl;*/
	//print(arr);
	//cout << "Reverse\n";
	//reverse(arr, arr + size(arr));
	//print(arr);

	//int key = 12;
	//cout << "\nCount of value " << key << ": " << count(arr, arr + size(arr), key) << endl;
	//
	//cout << "Count of value < 0" <<": " << count_if(arr, arr + size(arr), isNegative) << endl;
	//cout << "Count of even values " <<": " << count_if(arr, arr + size(arr), isEven) << endl;
	//
	//return 0;

	//array <string, 4> words{ "C++", "OOP", "STL", "Iterator" };
	//print(words);
	//
	//sort(begin(words), end(words));
	//print(words);
	//
	//cout << "Front : " << words.front() << endl;
	//words.back() = "stl";
	//cout << "Back : " << words.back() << endl;

	//return 0;
	/*int fixed[]{ 100, 200, 456, 90 };
	cout << "fixed Array :\n";
	for (int & i : fixed)
	{
		cout << "\t" << ++i << endl;
	}*/

	srand(unsigned(time(0)));
	// vector - клас, у якому інкапсульовано динамічно розширюваний масив    T * array
	vector <int> v { 10, 22, -5, 7 };// size = 4
	//v.reserve(20);// просимо  своє capacity
	cout << "Actual  size : " << v.size() << endl;
	print(v);
	cout << "\nPush elements :\n";
	for (size_t i = 0; i < 7; i++)
	{
		int rnd = rand() % 100;
		cout << "\t\tAdd(push) " << rnd << endl;
		v.push_back(rnd);
		print(v);
		cout << "Reserve  size(capacity) : " << v.capacity() << endl;// >=4 capacity =  резервний розмір  для вектора(розмір памяті із запасом)
	}
	v.pop_back(); // вилучення останнього елемента
	cout << "\nRemove last  element :\n";
	print(v);

	int index;
	cout << "Enter index of element  to  delete : ";
	cin >> index;
	if (index < v.size())
	{
		v.erase(begin(v) + index);// вказівник(ітератор) на елемент / begin(v) =  вказівник(ітератор) на 0-й елемент вектора
		cout << "\nRemove   element # " << index << ":\n";
		print(v);
	}
	cout << "\nEnter index of element  to  insert : ";
	cin >> index;
	int value;
	if (index < v.size())
	{
		cout << "Enter value to  insert : ";
		cin >> value;
		v.insert(begin(v) + index, value);
		cout << "\nInsert new    element # " << index << ":\n";
		print(v);
	}

	/*cout << "\nTransform with mult2()\n";
	transform(begin(v), end(v), begin(v), mult2);
	print(v);*/

	cout << "\nTransform with sqr()\n";
	transform(begin(v), end(v), begin(v), sqr);
	print(v);
	
	cout << "\nInput value for search : ";
	cin >> value;
	auto  it = find(begin(v), end(v), value); //пошук значення у контейнері, повертається ітератор(вказівник) на шукане значенння, або повертається  end(v), якщо знайденого
	if (it != end(v))
	{
		cout << "Value " << value << " was found in " << it - begin(v) << endl;
	}
	else
	{
		cout << "Value " << value << " not found\n";
	}
	vector<int> v2( 7, -1);
	cout << "\nActual  size v2: " << v2.size() << endl; // 7
	cout << "Reserve  size(capacity) : " << v2.capacity() << endl;// >=7
	print(v2);

	for (size_t i = 0; i < size(v); i++)
	{
		cout << v[i] << "\t";
	}

}


