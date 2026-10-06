#include "House.h"

House::House(const string& address)
	: kitchen(3, 5, "Kitchen") // тепер кухня буде 3х5
	, address(address), numRooms(2)
{
	cout << "\t\tHouse created\n";
	rooms = new Room[numRooms];// 4x4 Noname   4x4 Noname, будуть працювати деволтні конструктори для кожного елемента масиву(Room)
}

House::House(const string& address, int widthKitchen, int lenhthKitchen)
	: address(address), kitchen(widthKitchen, lenhthKitchen, "Kitchen")
	, rooms(new Room[numRooms=2])
{
	cout << "\t\tHouse created ctor with size of kitchen\n";
}

void House::print() const
{
	cout << "House address : " << address << endl;
	kitchen.print();
	for (int i = 0; i < numRooms; i++)
	{
		rooms[i].print();
	}
}

House::~House()
{
	if (rooms != nullptr)
	{
		delete[] rooms; // будуть працювати деструктори для кожного елемента масиву(Room)
		rooms = nullptr;
	}
	cout << "\t\tHouse destroyed\n";
	// також  спрацює  деструктор для кухні (kitchen)
}
