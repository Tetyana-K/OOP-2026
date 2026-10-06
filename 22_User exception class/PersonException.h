#pragma once
#include <exception>
#include <string>
using  namespace std;
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
	string message;
	T  errValue;// name(T=string) or age(T=int)
};

class BadNameException : public PersonException <string> // string errValue
{
	public:
		BadNameException(const  string& name, const  string& message = "Bad name")
			: PersonException(name, message)
		{}
};

class BadAgeException : public PersonException <int> //  int errValue
{
public:
	BadAgeException(const  int& age, const  string& message = "Bad age")
		: PersonException(age, message)
	{}
};

