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

int Pupil::operator[](int index) const
{
	if(isValidIndex(index))
		return marks[index]; // повертається КОПІЯ оцінки
	cerr << ">>>>> Error index of mark " << index << endl;
	exit(1);
}

int& Pupil::operator[](int index)
{
	if (isValidIndex(index))
		return marks[index];//  повертається посилання на елемент масиву 
	cerr << ">>>>>> Error index of mark " << index << endl;
	exit(1);
}

Pupil& Pupil::operator=(const Pupil& other)
{
	cout << "******* OPERATOR =\n";
	if (this != &other)  // перевірка чи не виконується присвоєння  самому собі
	{
		name = other.name;
		grade = other.grade;
		numMarks = other.numMarks;
		delete [] marks;//видалили старий масив оцінок, бо будемо створювати новий
		marks = new int[numMarks];

		for (int i = 0; i < numMarks; i++)
		{
			marks[i] = other.marks[i];
		}
	}
	return *this;
}

Pupil::~Pupil()
{
	cout << "\n~~~~~~ Dtor for " << name << " done\n";
	delete[] marks;//вилучили дин масив
}

void Pupil::operator()(const string& name, int grade)
{
	this->name = name;
	this->grade = grade;
}

