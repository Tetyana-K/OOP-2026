// 25_STL_deque.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <ctime>


using namespace std;
template<typename TCont>
void printCont(const TCont& d, string text = "") // ф-я зможе вивести елементи довільного контейнера, шо він  проходиться циклом rfor
{
	cout << text << endl;
	for (auto& i : d)
	{
		cout << "\t" << i;
	}
	cout << endl;
}
bool isNegative(int number) // predicat
{
	return number < 0;
}
int main()
{
	deque<int> d { 10, 23, 45, -33, 77, 55 };
	d.push_front(122); // 122 10, 23, 45, -33, 77, 55 
	d.push_back(-5); // 122 10, 23, 45, -33, 77, 55 , -5
	d.push_back(55);// 122 10, 23, 45, -33, 77, 55 , -5, 55
	printCont(d, "\tDeque<int>");

	d.insert(begin(d) + size(d) / 2, 777);
	d.insert(begin(d) + 1, { -1, -2, -3 });
	printCont(d, "\n\tDeque<int> after insert 777 and {-1 -2 -3}");

	d.erase(begin(d) + size(d) / 2);
	printCont(d, "\n\tDeque<int> after erase central  element");
	d.erase(begin(d), begin(d) + 3); // вилучення перших  3-  елементів
	printCont(d, "\n\tDeque<int> after erase firts 3   elements");


	int value;
	cout << "\nEnter value : ";
	cin >> value;
	auto itf = find(begin(d), end(d), value); // шукаємо value, повертається ітератор на елемент або end(d), якщо немає 
	while (itf != end(d))
	{
		//cout << "Found  value " << value << " in index " << itf - begin(li) << endl; // it1-it2 для продвинутих ітераторів
		cout << "Found  value " << value << " in index " << distance(begin(d), itf) << endl; // it1-it2 для продвинутих ітераторів
		itf = find(++itf, end(d), value);
	}
	cout << endl;
	// предикат -  логічна функція
	itf = find_if(begin(d), end(d), isNegative);//пошук першого входження відємного елемента у деку d
	if (itf != end(d))
	{
		cout << "First negative is " << *itf << endl;// *itf  -  отримуємо саме відємне число
	}
	else
	{
		cout << "Not found any  negative numbers\n";
	}

}



