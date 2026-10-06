#include "Shop.h"

void Shop::add(BaseProduct* product)
{
	products.push_back(product);
}

void Shop::showAll() const
{
	cout << "______List of products_______\n";
	for (auto& p : products)
	{
		p->show();
	}
}

Shop::~Shop()
{
	for (auto& i : products)
	{
		delete i;
	}
}
