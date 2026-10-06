#pragma once
#include "BaseProduct.h"
class Dairy :
    public BaseProduct
{
private:
    int fat;
public:
    Dairy(const string& name = "Noname", double price = 0, int fat = 0);
    void show() const override;
    void input() override;
};

