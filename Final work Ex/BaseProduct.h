#pragma once
#include <iostream>
#include <string>
using namespace std;

class BaseProduct
{
private:
	string name = "Noname";
	double price = 0;
public:
	BaseProduct() = default;
	BaseProduct(const string & name , double price);
	virtual void show() const = 0;
	virtual void input() = 0;
};

