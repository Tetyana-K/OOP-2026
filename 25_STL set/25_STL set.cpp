// 25_STL set.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <set>
using namespace std;
int main()
{
    set<int> s = { 10, 2, 10, 3, -5, -67 }; // множина, ВПОРЯДКОВАНИЙ набір даних, БЕЗ ПОВТОРІВ
    //multiset<int> s = { 10, 2, 10, 3, -5, -67 }; // множина, ВПОРЯДКОВАНИЙ набір даних, З ПОВТОРAМИ
    srand(unsigned(time(0)));

    s.insert(rand() % 100); // add number to set
    
    cout << "Print set :\n";
    for (auto& e : s) // range for loop
    {
        cout << "\t" << e;
    }
    cout << endl;

    cout << "Print set by iterator :\n";
    for (auto it = begin(s); it != end(s); ++it) // it = iterator
    {
        cout << "\t" << *it;
    }
    cout << endl;

    cout << "Print set by reverse iterator :\n";
    for (auto it = rbegin(s); it != rend(s); ++it) // it = reverse iterator (from right to left)
    {
        cout << "\t" << *it;
    }
    cout << endl;

    int value;
    cout << "\nEnter the search value : ";
    cin >> value;
    auto it = s.find(value); // пошук елемента у множині, повертається ітератор на  елемент, або end(s), якщо елемента немає 
    if (it!=end(s))
    {
        cout << "Found element " << value << " in index " << distance(begin(s), it) << endl;
    }
    else
    {
        cout << "Not found " << value << endl;
    }

    cout << "\nEnter the value to remove : ";
    cin >> value;
    //1) можна вилучити елемент через ітератор
    it = s.find(value); 
    if (it != end(s))
    {
        s.erase(it);
        cout << "Element " << value << " successfully removed\n";
    }
    //2) можна вилучити елемент за значенням
    
    cout << "\nEnter the value to remove : ";
    cin >> value;
    if (s.erase(value) != 0)
    {
        cout << "Element " << value << " successfully removed\n";
    }

    cout << "\nPrint set :\n";
    for (auto& e : s) // range for loop
    {
        cout << "\t" << e;
    }
    cout << endl;
}
