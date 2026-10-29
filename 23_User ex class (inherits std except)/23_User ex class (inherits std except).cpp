

#include <iostream>
#include <string>
using namespace std;
//class TrianError : public logic_error // користувацький тип винятку МОЖНА успадкувати від станд. класу винятку (what)
//{
//public:
//	TrianError(const string& errMessage) // конструктор класу, приймає рядок з описом помилки
//		: logic_error(errMessage )// викликаємо конструткор базового класу logic_error
//	{
//
//	}
//	
//};
class TrianError // можемо побудувати клас помилки з нуля( не спираючись на інші типи)
{
private:
	string errMessage;
public:
	explicit TrianError(const string& errMessage) // конструктор класу, приймає рядок з описом помилки
		: errMessage(errMessage)
	{
	}

	const string& what() const
	{
		return errMessage;
	}

};
double areaTrian(double base, double height)
{
	if (base <= 0 || height <= 0)
		throw TrianError("base <= 0 or height <=0");
	return base * height / 2;
}
void demo(const TrianError &t)
{
	cout << "In function demo\n";
}
int main()
{
	/*string str = "some string";
	demo(str);*/

	double base;
	double height;

	cout << "\t\tEnter base and height : ";
	cin >> base >> height;
	try
	{
		cout << "Area of traingular = " << areaTrian(base, height) << endl;
	}
	//catch (const std::exception& ex)
	catch (const TrianError& ex)
		//catch (const std::logic_error& ex)
	{
		cout << "Catch error of type : " << typeid(ex).name() << endl;
		//cout << "Message : " << ex.what() << endl;
	}
}

// Визначити глоб. функцію обчислення площі трикутника за 3-ма сторонами(ф-ла Герона). У випадку невірних  сторін кидати винятки типу string  або char *, якщо якась із сторін відємна
// У випадку нескладання трикутника(a >= b + c ) викидати виняток типу invalid_argument

