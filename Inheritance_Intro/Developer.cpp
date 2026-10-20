#include <iostream>
#include "Developer.h"
using std::cout;
using std::endl;
Developer::Developer(const string& name, int age, const string& companyName)
	: Human(name, age), // викликаємо конструктор базового класу, якщо цього не написати, то викличеться к-р по дефолту 
	companyName(companyName)
{
	//this->name = name; // немає прямого доступу до приватного поля з базового класу
	//this->age = age; //  так можна, бо age protected
	//this->companyName = companyName;

	//cout << "Constructor for Develper for " << this->name << endl;
	cout << "Constructor for Developer for " << getName() << endl;
}

Developer::~Developer()
{
	cout << "~~~~~~ Destructor for Developer " << getName() << endl;

}

void Developer::learn() const
{
	cout << "Developer " << getName() << " (" << age << ") from company " << companyName << " is learning\n";

}

void Developer::coding() const
{
	cout << "Developer " << getName() << " (" << age << ") from company " << companyName << " is coding\n";
}
