#pragma once
#include "Person.h"
class Developer :
    public Human  // клас Deveoper  успадкував всі поля та методи (приватні, захищені та публічні)
{
    // name - напряму НЕдоступний, бо у базовому класі приватний 
    // age - напряму доступний, бо у базовому класі захищений
    // eat(), walk(), learn() -  залишаються public, бо маємо public успадкування

public:
    Developer(const string& name = "Noname", int age = 18, const string& companyName = "DevCompany");
    ~Developer();

    /*virtual*/ void learn() const /*override*/; // цей метод ми вирішили трохи змінити, він перекриє (заховає 'hides')  відповідний метод із базового класу
    void coding() const;
private:
    string companyName;
};

