// 05_Cascade ctor  and Copy ctor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include "Pupil.h"

Pupil createPupil()
{
    string name; //  локальні змінні для введення у них імені та року навчання учня
    int grade;

    cout << "Input name : ";
    cin >> name;
    
    cout << "Input grade : ";
    cin >> grade;

    Pupil pupil(name, grade);//  сторюємо об'єкт учня через конструктор з 2-ма параметрами
    int mark;
    for (int i = 0; i < Pupil::NUM_MARKS; i++)
    {
        cout << "Enter mark #" << i << " : ";
        cin >> mark;
        pupil.setMark(i, mark);
    }
   
    cout << "++++++ In fun " << &pupil << endl;// перевірка адреси створеного обєкта
    return pupil;// COPY CTOR мав би спрацювати,  але компілятор оптимізував код, і передав створений обєкт у точку виклику
}
void demo(Pupil pupil) // COPY CTOR
{
    cout << "In func demo\n";
    pupil.print();
    // work with copy of some pupil...
}

int main()
{
    std::cout << "_________Cascade ctors_______\n";

    Pupil pupil; // працює конструктор по замовчуванню name = NOname  grade = 1 0  marks = [ 0 0 0 0 0]
    pupil.print();
    pupil.setMark(0, 8);
    cout << endl;

	Pupil maria("Maria", 10);
    maria.setMark(0, 11);
    maria.setMark(1, 12);
    maria.setMark(1, 13);
    maria.setMark(-1, 12);
    maria.setMark(6, 12);

    maria.print();


    std::cout << "\n_________Copy ctor_______\n";
    Pupil ann("Ann", 7); // створили обєкт ann, name = "Ann", grade =7
    ann.setMark(0, 10);
    ann.setMark(2, 12); // marks = [10, 0, 12, 0 , 0]
    ann.print();

    //pupil = ann;// = тут працює  операція присвоєння (бо  пишемо у існуючий обєкт)
    Pupil clone = ann; // copy ctor, тут працює конструктор (бо створюється НОВИЙ обєкт clone )
    Pupil clone2 (ann); // copy ctor, тут працює конструктор (бо створюється НОВИЙ обєкт clone )
    cout << "\nClone of ann's object\n";
    clone.print();
    cout << endl;
    
    // Клас не має  динамічних полів, тому програма працює  добре,тут  працює наданий компілятором Конструктор Копії, який виконує ПОВЕРХНЕВЕ(shallow) КОПІЮВАННЯ
    // 
    
    //Pupil pupil2 = createPupil();
    //pupil2.print();
    //cout << "++++++ In main " << &pupil2 << endl;// бачимо, що адреси співпадають, тобто копія не створювалася

    demo(maria); // у функцію передається КОПІЯ об'єкту ann
    //cout << "\nEND OF MAIN()\n";
}


