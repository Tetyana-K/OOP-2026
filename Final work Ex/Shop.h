#pragma once
#include <vector>
#include "BaseProduct.h"
using namespace std;
class Shop
{
private:
	vector<BaseProduct*> products;
public:

	Shop() = default;
	void add(BaseProduct* product);
	void showAll() const;
	~Shop();
};

