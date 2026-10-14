#pragma once
#include <string>
using namespace std;
class Employee
{
public:
	//explicit //- явний
	// explicit - забороняє використання неявного приведженні інших типів до нашого Employee
	Employee(const string& name, const  int& salary);
	explicit Employee(const string& name);
	//Employee() = default;
	Employee();
	void print() const;// метод екземпляра, викликається з-під об'єкта, стосується об`єкта
	
	static void simplePrint(const Employee & emp);

	static int getCount(); // Не стосується обєкта, стосується КЛАСУ, НЕ отримує this
	static const string& getCompany(); // статичний метод-гетер назви компанії 
	static void setCompany(const string& company); // статичний метод для зміни назви компанії 

private:
	
	static int counter;// = 0; статичні змінні(поля) класу у С++ доведеться визначати за межами класу
	static string company;// = "Noname";
	
	string name; // поле екземпляру
	const int id;// = ++counter; // якщо визначити як const, не зможемо надалі змінювати id 
	int salary = 7800; //нестатичне поле =  поле екземпляру

};
// Static метод 1) працює із статичними полями або (і) 2) приймає об'єкт(и) класу і їх обробляє

/*
Створіть клас Product, який описує товар.
Клас повинен містити:
- поле name — назва товару;
- поле price — ціна товару;
- статичне поле count — кількість створених товарів;
- конструктор, який ініціалізує назву товару та ціну та збільшує лічильник;
- статичний метод getCount(), який повертає кількість створених об’єктів.
- метод виведення інформації про товар
Завдання: Створіть 3-5 об’єктів класу Product. За допомогою статичного методу отримайте та виведіть кількість створених об’єктів.

*/

