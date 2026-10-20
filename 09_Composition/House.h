#pragma once
#include "Room.h"

class House
{
public:
	House(const string& address);
	House(const string& address, int widthKitchen, int lenhthKitchen);
	void print()const;
	void SetRoomSize(int index, int width, int length);
	void SetRoomName(int index, const string& name);
	~House();
private:
	Room kitchen; // room 
	Room* rooms; // дин масив з  кімнат
	int numRooms; // число кімнат
	// Room rooms[5];
	string address;

	bool isValidRoomIndex(int index)
	{
		return index >= 0 && index < numRooms;
	}
};

