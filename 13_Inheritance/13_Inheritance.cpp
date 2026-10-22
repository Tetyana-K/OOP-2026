// 13_Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Полімморфізм - один інтерфес ---> багато реалізацій (одному імені функції відповідають багато реалізацій)
// Два види поліморфізму - 
// 1) статичний (compile time, етап компіляції, раннє звязування) - перевантаження методів, операцій
// 2) динамічний (run time, етап виконання, пізнє звязування) -- віртуальні функції, перевизначення вірт функцій

// Для дин. полімофорфізму створюютьмя таблиці вірт. функцій для  поліморфних класів (тих, що містять вірт. функці)
// Компілятор пише додатковий код, який на етапі виконання буде шукати "правильну" функцію

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
	plane.increaseSpeed();
	//plane.Transport::move(); // Transport::move()
	cout << "\n\n";
	
	Ship ship("Kyiv", 2018);

	
	//ship.setBrand("Ukraine"); // setBrand() ----> protected, бо тип успадкування protected
	//ship.increaseSpeed();
	//ship.info(); // info() ----> protected
	ship.move();
	
	//cout << "\nPass transport into demo()\n";
	//demo(transport);
	
	cout << "\nPass plane into demo()\n";
	demo(plane);

	cout << "\nPass ship into demo()\n";
	//demo(ship); // так помилка компіляції, бо ship успадковний через protected
	demo((Transport&)ship); // треба явно перетворити під потрбдний тип
	//demo(static_cast<Transport&>(ship));
	cout << "\n____________________________\n";

	// у точку коду де очікується обєкт базового класу МОЖНА підставити обєкт похідного типу )
	// 1) public успадкування - просто підставити
	// 2) protected, private успадкування - доведеться звести до потрібного типу (casting) 
	cout << "________Array of transports____________\n";

	Transport* transports[] = { new Plane("Boeing", 2020, 7000), (Transport *)new Ship("Ukraine", 2023) };
	for (auto& t : transports)
	{
		t->info();
	}

}


