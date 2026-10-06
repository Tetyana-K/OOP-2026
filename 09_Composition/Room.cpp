#include "Room.h"

Room::Room(int width, int length, const string& name)
	: width(width), length(width), name(name)
{
	cout << "\t\tRoom " << name << " created\n";
}

void Room::print() const
{
	cout << "Room '" << name << "'\t" << width << "\t" << length << endl;
}

Room::~Room()
{
	cout << "\t\tRoom '" << name << "' destroyed\n";
}
