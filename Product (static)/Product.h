#pragma once
#include <string>
using std::string;
class Product
{
public:
	Product(const string& name = "Noname", int price = 0);
	void print() const;

	static void cmpByPrice(const Product& product1, const Product& p2);
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




