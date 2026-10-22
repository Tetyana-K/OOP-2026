#include <iostream>
using std::cout;
using std::endl;
#include "Person.h"
Human::Human(const string& name , int age )
	:name(name), age(age)
{
	cout << "----------Conctructor for Person " << name << "(" << age << ")\n";
}

void Human::walk() const
{
	cout << "Person " << name << "(" << age << ")" << " is walking\n";
}
void Human::eat() const
{
	cout << "Person " << name << "(" << age << ")" << " is eating\n";

}
void Human::learn() const
{
	cout << "Person " << name << "(" << age << ")" << " is learning\n";

}
void Human::learn(int hours) const
{
	cout << "Person " << name << "(" << age << ")" << " is learning " << hours <<
		"hours\n";
}
Human :: ~Human()
{
	cout << "~~~~~~ Destructor for Person " << name << endl;
}