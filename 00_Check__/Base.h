#pragma once
class anotherClass;
#include "Another.h"
class base {
private:
    int private_variable;

protected:
    int protected_variable;

public:
    base()
    {
        private_variable = 10;
        protected_variable = 333;
    }

    // friend function declaration
    friend void anotherClass::memberFunction(base&);
};

