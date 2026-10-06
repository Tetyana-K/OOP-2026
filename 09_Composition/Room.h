#pragma once
#include <string>
#include <iostream>
using namespace std;
class Room
{
public:
	Room(int width = 4, int length = 4, const string& name = "Noname");
	void print() const;
	~Room();
private:
	int width, length;
	string name;
};

