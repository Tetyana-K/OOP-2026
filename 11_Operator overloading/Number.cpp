#include "Number.h"

ostream& operator<<(ostream& out, const Number& obj)
{
	out << "*****" <<obj.getNumber();
	return out;
}

istream& operator>>(istream& in, Number& obj)
{
	double value; // додаткову змінну
	in >> value;// у цю змінну прочитали із потоку
	obj.setNumber(value);

	return in;
}
