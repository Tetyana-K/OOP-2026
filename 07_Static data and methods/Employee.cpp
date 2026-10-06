#include <iostream>

#include "Employee.h"

int Employee::counter  = 0; //  статичні змінні(поля) класу у С++ доведеться визначати за межами класу
string Employee::company = "Noname";
Employee::Employee(const string& name, const int& salary)
	: Employee(name)
{
	this->salary = salary;
}

Employee::Employee(const string& name)
	:name(name), id(++counter)
{
	//id = ++counter; 
	
	// ++counter - лічимо + 1 працівника
	// id = counter, 
}

void Employee::print() const
{
	cout << "Employee id     : " << id << endl;
	cout << "Employee name   : " << this->name << endl;
	cout << "Employee salary : " << salary << endl;
	cout << "Company         : " << company << endl;
	cout << endl;
}

void Employee::simplePrint(const Employee& emp)
{
	cout << emp.id << "\t" << emp.name << "\t" << emp.salary << endl;
}

int Employee::getCount() // працює із  статичним полем
{
	//this->  статична функція НЕ отримує this
	return counter;
}

const string& Employee::getCompany()
{
	return company;
}

void Employee::setCompany(const string& company)
{
	if (!company.empty())
	{
		Employee::company = company;
	}
}

Employee::Employee()
	:Employee("Noname")
{
}
