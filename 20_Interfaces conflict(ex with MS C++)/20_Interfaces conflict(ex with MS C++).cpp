
#include <iostream>
using namespace std;
#include "Shapes.h"
class Demo {};
int main()
{
	Circle c(10);
	cout << c.area() << endl;

	IShape& shape = c;
	cout << shape.area() << endl;

	Square s(5);
	//s.show(); // OK -  якщо є публічна реалізація на ОБИДВА ІНТЕРФЕЙСИ
	IShape* ptr = &s;
	cout << ptr->area() << endl;
	cout << ptr->length() << endl;

	cout << "\n___Square as IPrint___\n";
	((IPrint&)s).show();// IPrint::show()

	cout << "___Square as IDraw___\n";
	((IDraw&)s).show(); // IDraw::show()

	//int aa = 12;
	Demo  demo;
	IPrint* printable[] = { &c, &s, new Square(7)/*, (IPrint*)&aa*/ };// --unsafe code - комп - р буде перетворювати, на  етапі виконання - помилка
		//static_cast<IPrint*>(&demo) ok = бачимо помилковий каст на  етапі компіляції
	/*};*/

	std::cout << "_______Printable _____\n";
	for (IPrint* p : printable) // for range
	{
		p->show();
	}


}
