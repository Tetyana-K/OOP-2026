#include "House.h"

House::House(const string& address)
	: kitchen(3, 5, "Kitchen") // тепер кухня буде 3х5 - тут викликається конструктор з параметрами для внутррішнього обєета kitchen
	, address(address)
	, numRooms(2)
{
	rooms = new Room[numRooms];// 4x4 Noname   4x4 Noname, будуть працювати деволтні конструктори для кожного елемента масиву(Room)
	cout << "\t\tHouse created\n";
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

void House::SetRoomSize(int index, int width, int length)
{
	if (isValidRoomIndex(index))
	{
		rooms[index].width = width;
		rooms[index].length = length;

	}
}

void House::SetRoomName(int index, const string& name)
{
	if (isValidRoomIndex(index))
	{
		// rooms[index].name = name; -- так вийде, якщо маємо House як друга для Room
		rooms[index].setRoomName(name);
	}
}

House::~House() // якщо реалізуємо відношення Композиція, то при знищенні складного об'єкта мають знищуватися його частини 
{
	cout << "\t\tHouse destroyed\n";
	if (rooms != nullptr)
	{
		delete[] rooms; // будуть працювати деструктори для кожного елемента масиву(Room)
		rooms = nullptr;
	}
	// також  спрацює  деструктор для кухні (kitchen)
}
