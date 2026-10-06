#include <iostream>
#include "Pupil.h"

Pupil::Pupil(const string& name, const int& grade)
	: name(name), grade(grade) // список ініціалізації
{
	//setName(name);
	//setGrade(grade);
	cout << "Ctor with 2 params for pupil name " << name << " done\n";
}
// визначимо к-р як делегуючий (каскадний), тобто що цей к-р для своєї роботи ВИКЛИЧЕ ІНШИЙ КОНСТРУКТОР нашого класу
Pupil::Pupil()
	: Pupil("Noname", 1)
{
	//Pupil("Noname", 1); -  так не спрацює виклик іншого к-ра
	cout << "Ctor defult\n";
	/*for (size_t i = 0; i < NUM_MARKS; i++)
	{
		marks[i] = -1;
	}*/
}

void Pupil::print() const
{
	cout << "Pupil name : " << name << endl;
	cout << "Pupil grade : " << grade << endl;
	printMarks();

}
// хочемо написати к-р копії  власноруч
Pupil::Pupil(const Pupil& other) 
	: Pupil(other.name, other.grade)
{
	/*name = other.name;
	grade = other.grade;*/
	for (int i = 0; i < NUM_MARKS; i++)
	{
		marks[i] = other.marks[i];
	}
	cout << "***** Copy  ctor done\n";
}

void Pupil::printMarks() const
{
	cout << "Marks :";
	for (const int& m : marks)
	{
		cout << "\t" << m;
	}
	cout << endl;
}

void Pupil::setMark(int index, int mark)
{
	if (isValidIndex(index) && isValidMark(mark))
	{
		marks[index] = mark;
	}
}

Pupil::~Pupil()
{
	cout << "~~~~~~~~~ Dtor for " << name << " done\n";
}
