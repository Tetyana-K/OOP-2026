#include <iostream>
using namespace std;
#include "Base.h"
#include "Another.h"
void anotherClass::memberFunction(base& obj)
{
    cout << "Private Variable: " << obj.private_variable
        << endl;
    cout << "Protected Variable: " << obj.protected_variable;
}
