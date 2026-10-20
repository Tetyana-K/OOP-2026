#pragma once
#include <string>
#include <iostream>
using namespace std;

class Room
{
public:
	Room(int width = 4, int length = 4, const string& name = "Noname");
	void print() const;
	void setRoomName(const string& name);
	~Room();
private:
	int width;
	int length;
	string name;

friend class House; // можемол зробити House другом для Room = обєкти Будинку мають прямий доступ  до закритої честини класу Кімната 
};

