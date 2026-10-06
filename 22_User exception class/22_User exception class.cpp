// 04-_User defined class excep.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Person.h"
void demo_1()
{
	Person person;// Noname 0
	try
	{
		person.setName("Ann");
		person.setName("");
		person.setName("Petro");
		person.setAge(-10);
		person.print();
	}
	catch (const BadNameException& ex)
	{
		cout << ex.what() << endl;
		cout << "Bad name : " << ex.getErrValue() << endl;
		//cout << "Bad name fixed to 'Noname'\n";
		//person.setName("Noname");
		person.print();
	}
	catch (const  BadAgeException& ex)
	{
		cout << ex.what() << endl;
		cout << "Bad age : " << ex.getErrValue() << endl;
		cout << "Bad age fixed to 0\n";
		person.setAge(0);
		person.print();
	}
	catch (const PersonException<string>& ex)
	{
		cout << "Catch PersonException <string> : " << ex.what() << endl;
	}
	/*catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}*/
	cout << "_____________________________\n";

	//try {
	//	Person someone("Oleh123", 30);
	//	someone.print();
	//}
	//catch (const BadNameException& ex)
	//{
	//	cout << ex.what() << endl;
	//	cout << "Bad name : " << ex.getErrValue() << endl;
	//	//cout << "Bad name fixed to 'Noname'\n";
	//	//person.setName("Noname");
	//	
	//};

	cout << "\n\nEND OF MAIN()\n";
}
void demoRethrow()
{
	try
	{

		Person person("A123", 22);
		person.print();
	}
	catch (BadNameException& ex)
	{
		cout << ex.what() << endl;
	}
}
int main()
{
	//demo_1();
	demoRethrow();
}


