#pragma once
#include <string>
using namespace std;
class Employee
{
public:
	//explicit //- явний
	Employee(const string& name, const  int& salary);
	/*explicit*/ Employee(const string& name);
	//Employee() = default;
	Employee();
	void print() const;// метод екземпляра, викликається з-під об'єкта, стосується об`єкта
	
	static void simplePrint(const Employee & emp);

	static int getCount(); // Не стосується обєкта, стосується КЛАСУ, НЕ отримує this
	static const string& getCompany();
	static void setCompany(const string& company);

private:
	static int counter;// = 0; статичні змінні(поля) класу у С++ доведеться визначати за межами класу
	static string company;// = "Noname";
	string name; // поле екземпляру
	const int id;// = ++counter; // якщо визначити як const, не зможемо надалі змінювати id 
	int salary = 7800;

};
// Static метод 1) працює із статичними полями або (і) 2) приймає об'єкт(и) класу і їх обробляє

