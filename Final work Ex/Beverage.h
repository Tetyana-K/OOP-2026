#pragma once
#include "BaseProduct.h"
class Beverage
	:public BaseProduct
{
private:
	double volume = 1.0;
public:
	Beverage(const string& name = "Noname", double price = 0, double volume = 1.0)
		:BaseProduct(name, price), volume(volume)
	{

	}
	void show() const override;
	void input()  override;

};

