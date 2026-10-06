// 27_STL_map.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, string> humans
    {
        {123, "Ivan"}, // first, second
        {20, "Olena"},
        {200, "Artem"},
    };
    int id;
    string name;
    cout << "Entetr id and name : ";
    cin >> id >> name;
    humans.insert({ id, name });

    humans[300] = "Serhii";// якщо пари немає з  ключем 300, то буде створена, якщо є - то буде заміна значення(second) пари

    for (auto& h : humans)
    {
        cout << h.first << "\t" << h.second << endl;
    }

    cout << "\nEnter search id : ";
    cin >> id;
    auto it = humans.find(id);

    if (it != end(humans))
    {
        cout << "Human with " << id << " found. Human's name is " << it->second << endl; // this way better
        //cout << "Human with " << id << " found. Human's name is " << humans[id] << endl; --  humans[id] повільніший, бо почне шукти з початку дерева
    }
    else
    {
        cout << "Human with #" << id << " not found\n";
    }
    cout << "\n\nEnter  id to delete human : ";
    cin >> id;
    humans.erase(id);
    for (auto& h : humans)
    {
        cout << h.first << "\t" << h.second << endl;
    }
}
