// 13_Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include "Transport.h"
#include "Plane.h"
#include "Ship.h"
// has a -  
// is a - inheritance
void demo(const Transport& t)
{
	cout << "_____ Function demo() get object by reference Transport &\n";
	t.info(); // буде працювати метод по типу Transport :: info(), якщо  не позначили його як віртуальний
	t.move();
}
int main()
{
	/*Transport transport("Vendor A", 2015);
	transport.setBrand("ABC Company");
	transport.info();
	transport.move();*/
	
	cout << "\n\n";
	
	

	Plane plane("Mriya", 2020, 7800);// к-р похідного класу  викликає к-р базового типу, і потім виконується власне тіло к-р похідного типу
	plane.setBrand("Ruslan");
	plane.info(); // Plane :: info()
	plane.move();// Plane:: move()
	//plane.Transport::move(); // Transport::move()
	cout << "\n\n";
	

	
	Ship ship("Kyiv", 2018);
	//ship.setBrand("Ukraine"); // setBrand() ----> protected, бо тип успаддкування protected
	//ship.info(); // info() ----> protected
	ship.move();
	
	//cout << "\nPass transport into demo()\n";
	//demo(transport);

	cout << "\nPass plane into demo()\n";
	demo(plane);

	cout << "\nPass ship into demo()\n";
	demo((Transport&)ship);
	//demo(static_cast<Transport&>(ship));
	cout << "\n____________________________\n";

	// у точку коду де очікується обєкт базового класу МОЖНА підставити обєкт похідного типу )
	// 1) public успадкування - просто підставити
	// 2) protected, private успадкування - доведеться звести до потрібного типу (casting) 


}


