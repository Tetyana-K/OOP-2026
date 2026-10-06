#pragma once
#include "Shop.h"
class Menu
{
private:
	Shop* shop;
	enum {ADD = 1, SHOW, SEARCH, EXIT};
public:
	Menu(Shop* shop);
	void print()const;
	void subMenuProducts();
	void run();
};

