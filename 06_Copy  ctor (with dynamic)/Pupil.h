#pragma once
#include <string>
using namespace std;
class Pupil
{
public:
	static const int MAX_MARK = 12; // статична константа, існує  у ОДНОМУ екземплярі для усіх  обєктів класу, 
	Pupil(const string& name, const int& grade, int numMarks = 3);
	
	Pupil();
	Pupil(const Pupil& other); // copy  ctor
	void print() const;
	void printMarks() const;
	void setMark(int index, int mark); // метод виставлення  оцінки за індексом
	~Pupil();
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



