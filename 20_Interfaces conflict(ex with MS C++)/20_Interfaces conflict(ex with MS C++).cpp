
#include <iostream>
using namespace std;
#include "Shapes.h"
class Demo {};
int main()
{
	Circle c(5);
	c.setRadius(10);
	cout << c.area() << endl;


	IShape& shape = c;// можна створити посилання чи вказівник на інтерфейс  та присвоїти йому посилання (вказівник) на клас, який реалізувіав цей інтерфейс 
	cout << shape.area() << endl; 
	// через  посилання shape можемо викоикати тільки методи які з IShape

	IPrint* ip = &c;
	ip->show();
	
	Square s(5);
	//s.show(); // OK -  якщо є публічна реалізація на ОБИДВА ІНТЕРФЕЙСИ

	IShape* ptr = &s; // дивимося на квадрат через призму Ishape
	cout << ptr->area() << endl;
	cout << ptr->length() << endl;

	cout << "\n___Square as IPrint___\n";
	((IPrint&)s).show();// IPrint::show()

	cout << "___Square as IDraw___\n";
	((IDraw&)s).show(); // IDraw::show()

		
	//int aa = 12;
	Demo  demo;
	IPrint* printable[] = { &c, &s, new Square(7)/*, (IPrint*)&aa*/ };// --unsafe code - комп - р буде перетворювати, на  етапі виконання - помилка
	
	//static_cast<IPrint*>(&demo);// error = бачимо помилковий каст на  етапі компіляції
	static_cast<IPrint*>(&c)->show();// ok, бо об'єкт c (клас Square), Square реалізував інтерфейс IPrint
	

	std::cout << "_______Printable _____\n";
	for (IPrint* p : printable) // for range
	{
		p->show();
	}

	cout << "\n_____ IShape* array________\n";
	IShape* shapes[] = { &c, &s, new Circle(4)};
	for (auto& sh : shapes)
	{
		cout << "Area = " << sh->area() << endl;
		cout << "Length = " << sh->length() << endl;
	}
	//delete printable[2];
	//delete shapes[2];
}
