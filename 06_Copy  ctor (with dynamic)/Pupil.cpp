#include "Pupil.h"
#include <iostream>
#include "Pupil.h"

Pupil::Pupil(const string& name, const int& grade, int numMarks)
	: name(name), grade(grade), numMarks(abs(numMarks)) // список ініціалізації
{
	marks = new int[this->numMarks] {};// створили память для дин масиву оцінок
}

Pupil::Pupil()
	: Pupil("Noname", 1)
{	
}

void Pupil::print() const
{
	cout << "Pupil name : " << name << endl;
	cout << "Pupil grade : " << grade << endl;
	printMarks();

}
// ПОТРІБНО написати к-р копії  власноруч, який виділить память для масиву оцінок, скопіює  оцінки, скопіює інші поля
Pupil::Pupil(const Pupil& other) :
	Pupil(other.name, other.grade, other.numMarks)
{
	/*name = other.name;
	grade = other.grade;
	numMarks = other.numMarks;
	marks = new int[numMarks] {}
	*/
	for (int i = 0; i < numMarks; i++)
	{
		marks[i] = other.marks[i];
	}
	cout << "***** Copy  ctor done\n";
}

void Pupil::printMarks() const
{
	cout << "Marks :";
	for (int i =0; i < numMarks; ++i)
	{
		cout << "\t" << marks[i];
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
	cout << "\n~~~~~~ Dtor for " << name << " done\n";
	delete[] marks;//вилучили дин масив
}

