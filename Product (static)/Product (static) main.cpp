// Product (static).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include "Product.h"

void test()
{
    Product arr[2];
    cout << "Count of products from func test() = " << Product::getCounter() << endl;


}

int main()
{
    //Product::counter = 100;

    Product juice ("Apple juice", 770);
    juice.print();
    cout << "Count of products = " << Product::getCounter() << endl;

    Product products[3] { { "Ice-cream", 505 }, { "Prague cake", 400 } };
    cout << "--List of products----------\n";
    cout << "Count of products = " << Product::getCounter() << endl;
    for (auto& p : products )
    {
        p.print();
    }

    test();

    cout << "Count of products = " << Product::getCounter() << endl;

    Product::cmpByPrice(products[0], products[1]); // так гарно викликати статичніий метод, через ім'я класу
    juice.cmpByPrice(products[0], products[1]);// так не гарно, плутає нас, juice тут не використовується у функції, бо статична функція класу НЕ отримує this
}


