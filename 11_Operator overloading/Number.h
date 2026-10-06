
#pragma once
#include <string>
#include <iostream>
using std::string;
using std::ostream; // тип підходить для стандартного обєкта cout (clog, cerr) 
using std::istream; // тип підходить для стандартного обєкта cin
// wrapper = клас - обгортка ( у нас обгортка дробового числа)
class Number
{
public:
	explicit Number(double number = 0); // explicit -  явний, дозволяється конструюти обєкти явним чином
	double getNumber()const;
	void setNumber(double number);
	Number operator + (const Number & right) const; // left = this
	Number operator / (const Number & right) const; // left = this
	bool operator == (const Number& right) const; // left = this
	bool operator != (const Number& right) const; // left = this

	Number& operator ++(); // this= єдиний аргумент, унарна операція ++ префіксна форма
	Number operator ++(int); // унарна операція ++ постфіксна форма, int -  фіктивний параметр для позначення постфікса 

	friend Number operator -(const Number& first, const Number& second); //  глобальна ДРУЖНЯ функція для перевантаження операції -
// операція зведення до  іншого типу (тут  до string)
	/*explicit*/ operator string()const; // explicit -  клієнт класу зможе використовувати тільки ЯВНЕ приведення типу 
private:
	double number;
};
ostream& operator << (ostream& out, const Number& obj);
istream& operator >> (istream& in,  Number& obj);
// глобальна функція для перевантаження операції множення (бінарна операція, тому 2 параметри у функції)

inline Number operator *(const Number& first, const Number& second)
{
	//first.number -  глобальна функція не бачить приватного поля
	Number result(first.getNumber() * second.getNumber());
	return result;
}
inline Number operator -(const Number& first, const Number& second)
{
	Number result(first.number - second.number);//first.number  OK-  глобальна функція Друг класу
	return result;
}
inline Number::Number(double number)
	: number(number)
{
}
inline double Number::getNumber() const
{
	return number;
}

inline void Number::setNumber(double number) 
{
	this->number = number;
}

inline Number Number::operator+(const Number& right) const //this = left
{
	return Number(number + right.number);
}

inline Number Number::operator/(const Number& right) const
{
	return Number(number/ right.number);
}

inline bool Number::operator==(const Number& right) const
{
	return number == right.number;
}

inline bool Number::operator!=(const Number& right) const//this = left
{
	//return number != right.number; // можемо перепрограмувати, бо тут це просто ()
	return !(*this == right); // ми викликали визначену раніше операцію ==, і заперечили результат 
}

inline Number& Number::operator++()
{
	++number;
	return *this; // повертаємо самого себе (за посиланням), обєкт для його викликана операція
}

inline Number Number::operator++(int)
{
	Number tmp = *this; // copy ctor
	//Number tmp(number);
	//++number; // дублювання коду збільшення на 1, зараз  це не складно
	++ * this;// уникнули дублювання коду, використали раніше визначений префіксний ++ 
	return tmp;
}

inline Number::operator string() const // операція зведення до типу string
{
	return std::to_string(number); // застосували стд. функці. перетворення числа у рядок
}

