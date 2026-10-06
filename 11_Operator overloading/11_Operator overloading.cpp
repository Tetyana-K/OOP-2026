// 11_Operator overloading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// Перевантаження операцій =  надання можливості використовувати операції мови для користувацьких типів
// Не можна перевантажити операції . :: ?:  typeid sizeof 
// 2 способи                            operator <znak>
//        1) метод класу        MyClass operator + (const MyClass& obj2) {} // this =  1 аргумент(left), 2-й аргумент obj2 (right)
//              obj1 + obj2 // left + right
//          якщо операція бінарна, то метод отримує один аргумент неявно(this), другий  явно
//              ++obj1;   MyClass operator ++ () {...} // this =  1 аргумент
//          якщо операція унарна, то метод отримує один аргумент неявно(this)
//        2) глобальна операторна функція (може бути дружня)
//              якщо операція бінарна, то глобальна функція отримує два аргументи
//              якщо операція унарна, то глобальна функція отримує один  аргумент
#include <iostream>
using std::cout;
using std::endl;
using std::boolalpha;
using std::cin;
#include "Number.h"
int main()
{
    Number a(10);
    Number b(20);
    Number c = a + b; // використання перевантаженої операції +    c.number = 30
    Number m = a - b; // використання перевантаженої операції +    c.number = 30
    // a + b ------ компілятор ----- a.operator+(b)
    Number d = a / b;  // a / b ------ компілятор ----- a.operator/(b)
    Number f = a * b; // a * b ------ компілятор ----- operator *(a, b)

    cout << a.getNumber() << " + " << b.getNumber() << " = " << c.getNumber() << endl; 
    cout << a.getNumber() << " - " << b.getNumber() << " = " << m.getNumber() << endl; 
    cout << a.getNumber() << " * " << b.getNumber() << " = " << f.getNumber() << endl;
    cout << a.getNumber() << " / " << b.getNumber() << " = " << d.getNumber() << endl;
    cout << a.getNumber() << " == " << b.getNumber() << " = " << boolalpha <<(a == b) << endl;
    cout << a.getNumber() << " != " << b.getNumber() << " = " << boolalpha <<(a != b) << endl;

   // Number e = a + 7.5;// Number + Number = a(Number ok) + 7.5 (double---> ctor with 1 params) --- БУДЕ ПРАЦЮВАТИ, якщо конструктор не explicit 
    Number e = a + (Number)7.5;//так буде працювати завжди,  явне створення обєкта на основі 7.5
    cout << a.getNumber() << " + " << 7 << " = " << e.getNumber() << endl;


    a = b;// a = 20
    cout << "\na=  b\n" << endl;
    cout << a.getNumber() << " == " << b.getNumber() << " = " << boolalpha <<(a == b) << endl;
    cout << a.getNumber() << " != " << b.getNumber() << " = " << boolalpha <<(a != b) << endl;

    cout << "\n++ a = " <<(++a).getNumber(); // ++ префіксна форма   21
    cout << "\na++ = " <<(a++).getNumber(); // ++ постфіксна форма   21 на екрані, хоча а містиь 22
    cout << "\na = " << a.getNumber()<< "\n\n"; //  22

    string str = (string)a; // str = "22.000000"   працює операція перетворення обєкта Number у тип string
    string str2 = c; // str2 = "22.000000" працює операція перетворення обєкта Number у тип string
    string  concat = str + str2; // "22.000000" + "30.0000000" = "22.00000030.000000"
    cout << "str = " << str << endl;
    cout << "str2 = " << str2 << endl;
    cout << "concat  = str + str2 =  " << concat << endl;

    //int value = 50;
    //
    //cout << "\nValue = " << value << endl;// 1) int << int Left shift  2) cout << data  << output  operataion
    //cout << "\nValue << 1 = " << (value << 1) << endl;// 1) int << int Left shift  2) cout << data  << output  operataion

    // void operator << (ostream & out) const  // this = 1(NUmber) 2 ???? user    c << cout; - технічно можливо, але не зручно для користувача класу, тому обираємо спосіб перевантаження через  Глобальну функцію
    // void operator << (ostream & out, const Number & obj) {}
    cout << "\nNumber with  op << : " << c <<  endl;
    cout << "Input new double value for object c : ";
    cin >> c;
    cout << "After c = " << c << endl;
}


