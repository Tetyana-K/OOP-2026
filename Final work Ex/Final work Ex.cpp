// Final work Ex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Dairy.h"
#include "Beverage.h"
#include "Shop.h"
#include "Menu.h"
int main()
{
   /* Dairy milk("Milk", 27, 3);
    milk.show();*/

    Shop shop;
    Menu menu(&shop);
    
    menu.run();
    
}

