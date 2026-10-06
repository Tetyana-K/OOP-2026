#include "Menu.h"
#include "Beverage.h"
#include "Dairy.h"

Menu::Menu(Shop* shop)
	:shop(shop)
{
}

void Menu::print() const
{
	cout << "1. Add product\n";
	cout << "2. Show all\n";
	cout << "3. Search\n";
	cout << "4. Exit\n\n";

}

void Menu::subMenuProducts()
{
	enum { DAIRY = 1, BEVERAGE };
	cout << "\t1. Add dairy\n";
	cout << "\t2. Add beverage\n\n";
	int choice;
	cin >> choice;
	switch (choice)
	{
		case DAIRY:
		{
			BaseProduct* p = new Dairy();
			p->input();
			shop->add(p);
			break;
		}
		case BEVERAGE:
		{
			BaseProduct* p = new Beverage();
			p->input();
			shop->add(p);
			break;
		}
	}
}


void Menu::run()
{
	int choice;
	do {
		print();
		cin >> choice;
		switch (choice)
		{
		case ADD:
			subMenuProducts();
			break;
		case SHOW:
			shop->showAll();
			break;
		}
	} while (true);
}
