#pragma once
#include <string>
using std::string;
class Product
{
public:
	Product(const string& name = "Noname", int price = 0);
	void print() const;

	static int getCounter()
	{
		return counter;
	}
	~Product()
	{
		//--counter;
	}
private:
	string name;
	int price;
	static int counter;
};




