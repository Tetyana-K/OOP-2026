#pragma once
#include <exception>
#include <string>
using  namespace std;

//  класи користувацьких винятків

// базовий шаблонний клас винятку, на основі якого створимо класи конкретнихз винятків для роботи із Персоною
template<typename T>
class PersonException //: public invalid_argument
{
public:
	PersonException(const T& value = T(), const string& message = "Person exception")
		: /*invalid_argument(message.data()),*/ message(message), errValue(value)
	{}
	//const  char* what() const  override {}
	const T& getErrValue() const
	{
		return errValue;
	}
	const string& what() const
	{
		return message;
	}
private:
	string message; // рядок з описом помилки
	T  errValue;// name(T=string) or age(T=int) саме помилкове дане, хочемо різного типу (string, double) під різні поля Person
};

class BadNameException : public PersonException <string> // string errValue
{ // успадкували errorValue типу string,  message типу string,  методи what(),  getErrValue()
	public:
		BadNameException(const  string& name, const  string& message = "Invalid name")
			: PersonException(name, message)
		{}
};

class BadAgeException : public PersonException <int> //  int errValue
{
	// успадкували errorValue типу int,  message типу string, методи what(),  getErrValue()
public:
	BadAgeException(const  int& age, const  string& message = "Bad age")
		: PersonException(age, message)
	{}
};

