#pragma once
#include <iostream>
#include "PersonException.h"
#include <algorithm>
class Person
{
public:
	void setName(const string& name);
	void setAge(int  age);
	void  print()const;
	Person(const string& name = "Noname", const int& age = 0);
	~Person();
private:
	const static int MAX_AGE = 119;
	string name;
	int age;
};

inline void Person::setName(const string& name)
{
	if (name.empty())
		throw BadNameException(name, "Empty name!"); // кидається обєкт винятку типу BadNameException (errValue:name, errMessage : "Empty name!")

	if (! all_of(name.begin(), name.end(), [](char c) {return isalpha(c) ; }))// якщо не всі букви
	{
		throw BadNameException(name, "Expected only letter symbols"); // кидається обєкт винятку типу BadNameException (errValue:name, errMessage : "Expected only letter symbols")

	}
	this->name = name;
}

inline void Person::setAge(int age)
{
	if (age < 0)
		throw BadAgeException(age, "Negative age impossible!");
	if(age >  MAX_AGE)
		throw BadAgeException(age, "Age will be <=" + to_string(MAX_AGE) +"!");
	this->age = age;
}

inline void  Person::print()const
{
	cout << "Name : " << name << endl;
	cout << "Age : " << age << endl;
}

inline Person::Person(const string& name, const int& age)
{
	try 
	{
		setName(name);
		setAge(age);
	}
	catch (...)
	{
		cout << "Partial handling error in ctor\n";
		this->~Person();
		throw; // перевикинули (rethrow) виняток такого ж типу як прилетів, у зовнішній світ, буде шукатися більш зовнішній catch
	}
}

inline Person::~Person()
{
	cout << "~~~~~~~~ Dtor for Person~~~~" << name << "\n";
}
