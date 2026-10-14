//#include "Pupil.h"
#include <iostream>
#include "Pupil.h"

Pupil::Pupil(const string& name, const int& grade, int numMarks)
	: name{ name }, grade(grade), numMarks(abs(numMarks)),
	marks(new int[this->numMarks] {}) // список ініціалізації
{
	//this->name = name;
	//this->grade = grade
	/*if (numMarks > 0)
		this->numMarks = numMarks;
	else
		this->numMarks = 5;*/
	//marks = new int[this->numMarks] {};// створили память для дин масиву оцінок
}

Pupil::Pupil() // к-р без параметрів (дефолтний)
	: Pupil("Noname", 1) // каскадно викликається к-р з 3-ма параметрами(3-й по дефолту ) 
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
	//name = other.name;
	//grade = other.grade;
	//numMarks = other.numMarks;
	//marks = other.marks; -- так невірно, посилаємося на ділянку памяті із other, нам потрібна нова ділянка
	//marks = new int[numMarks] {}; // створбємо масив оцінок для поточного об'єкта
	
	for (int i = 0; i < numMarks; i++) // копіюємо оцінки із other у поточний об'єкт
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

Pupil::~Pupil() // деструктор, для класів з динам. полями необхідний, щоб уникнути витоку пам'яті  
{
	cout << "\n~~~~~~ Dtor for " << name << " done\n";
	if (marks != nullptr) {
		delete[] marks;//вилучили дин масив
		marks = nullptr;
	}
}

