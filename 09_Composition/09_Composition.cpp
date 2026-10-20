// 09_Composition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Room.h"
#include "House.h"
int main()
{
	/*Room room(5, 6, "Dining room");
	room.print();*/

	/*House house("Some address");
	house.print();*/

	House house2("Rivne, Garna Street", 5, 6);

	house2.SetRoomName(0, "Living room");
	house2.SetRoomSize(0, 5, 6);
	house2.SetRoomName(1, "Bed room");
	house2.print();
}

