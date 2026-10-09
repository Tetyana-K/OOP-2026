#pragma once
#include <string>
using namespace std;
class Pupil
{
	//const int NUM_MARKS = 5; // константа екземпляру, тобто 
	// 1)поле буде у кожного екземпляру 
	// 2) не можна змінити протягом часу життя обєкта 
	// 3) початково ініціалізують при визначенні поля або в конструкторі у списку ініціалізації
public:
	static const int NUM_MARKS = 5; // статична константа, існує  у ОДНОМУ екземплярі для усіх  обєктів класу, 
	static const int MAX_MARK = 12; // статична константа, існує  у ОДНОМУ екземплярі для усіх  обєктів класу, 
	
	Pupil(const string& name, const int& grade); // конструктор з 2-ма параметрами
	//Pupil()  = default; // означає прохання компілятору надати к-р по  замовчуванню, який нічого* робить 
	Pupil(); // контсруктор без параметрів
	
	Pupil(const Pupil& other); // copy  ctor = для копіювання іншого обєкта у наш
	
	void print() const;
	void printMarks() const;
	void setMark(int index, int mark); // метод виставлення  оцінки за індексом
	~Pupil(); // деструктор
private:
	string name;// = "Noname";
	int grade ; // 1-11
	int marks[NUM_MARKS] {};

	bool isValidIndex(int index)const;
	bool isValidMark(int mark)const;
};

inline bool Pupil :: isValidIndex(int index)const
{
	return index >= 0 && index < NUM_MARKS;
}
inline
bool Pupil::isValidMark(int mark)const
{
	return mark >= 0 && mark <= MAX_MARK;
}

