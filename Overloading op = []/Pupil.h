#pragma once
#include <string>
using namespace std;
class Pupil
{
public:
	static const int MAX_MARK = 12; // статична константа, існує  у ОДНОМУ екземплярі для усіх  обєктів класу, 
	Pupil(const string& name="Noname", const int& grade = 1, int numMarks = 3);
	
	Pupil();
	Pupil(const Pupil& other); // copy  ctor
	void print() const;
	void printMarks() const;
	void setMark(int index, int mark); // метод виставлення  оцінки за індексом
	int operator[] (int index) const; // [] працюватиме для const обєктів
	int& operator[] (int index);// int& - повертаємо посилання на оцінку(елемент масиву)
	//void operator = (const Pupil& other); // спрощений варіант, не зможемо каскадувати операцію = чи методи  (a = b = c), (a = b).setMark(0, 12)
	Pupil& operator = (const Pupil& other); // покращений  варіант,  зможемо каскадувати 
	~Pupil();

	void operator()(const string& name, int grade); // перевантажимо операцію виклику функції так, щоб зиінювати імя та клас учня
private:
	int numMarks; // кількість оцінок
	string name;// = "Noname";
	int grade; // 1-11
	int * marks = nullptr; // вказівник на динам масив оцінок

	bool isValidIndex(int index)const;
	bool isValidMark(int mark)const;


};
inline bool Pupil::isValidIndex(int index)const
{
	return index >= 0 && index < numMarks;
}
inline
bool Pupil::isValidMark(int mark)const
{
	return mark >= 0 && mark <= MAX_MARK;
}



