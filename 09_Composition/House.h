#pragma once
#include "Room.h"

class House
{
public:
	House(const string& address);
	House(const string& address, int widthKitchen, int lenhthKitchen);
	void print()const;
	~House();
private:
	Room kitchen; // room 
	Room* rooms; // дин масив з  кімнат
	int numRooms; // число кімнат
	// Room rooms[5];
	string address;
};

