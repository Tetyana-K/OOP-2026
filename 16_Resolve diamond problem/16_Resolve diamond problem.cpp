// Multi inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

// Вирішення Diamond Problem  - віртуальне  успадкування від класу Human класів Writer, Photographer
// Базовий  Human
class Human
{
protected:
    string name;
public:
    Human(const string& name)
        : name(name)
    {
        cout << "\t\t***Ctor Human " << name << endl;
    }
    ~Human()
    {
        cout << "\t\t***Dtor Human " << name << endl;
    }
};
// Writer - похідний клас, успадковує поле name від Human
class Writer : virtual public Human
{
protected:
    Writer(const string& name)
        : Human(name)
    {
        cout << "\t\tCtor Writer " << this->name << endl;
    }
public:
    void write() const
    {
        cout << name << " has writen the article" << endl;
    }
    ~Writer()
    {
        cout << "\t\tDtor Writer " << name << endl;
    }
};

//  Photographer -  похідний клас, теж успадковує поле name від Human
class Photographer : virtual  public Human
{
protected:
    int experience;

public:
    Photographer(const string& name = "Noname", int experience = 1)
        : Human(name), experience(experience)
    {
        cout << "\t\tCtor Photographer " << this->name << " with  experience of " << experience << " year(s)" << endl;
    }
    void takePhoto() const
    {
        cout << name << " has taken the photo" << endl;
    }
    ~Photographer()
    {
        cout << "\t\tDtor Photographer with name " << name << " and experience " << experience << endl;

    }
};

// Клас Photojournalist, який успадковує властивості від Writer і Photographer, тепер успадкував ОДИН екземпляр класу Human
class Photojournalist : public Writer, public Photographer
{
public:
    // якщо клас успадковує віртуально інші класи, то конструткор класу спочатку викликає конструктори ВІРТУАЛЬНИХ  базових  класів, потім звичайних базових  класів
    // тобто у нас спочатку викличеться к-р класу Human (через нього проініціалізується поле name), 
    //потім к-ри Writer та Photographer(які НЕ  БУДУТЬ чіпати ініціалізацію поля name)
    
    Photojournalist(const string& name = "Noname", int experience = 1)
        : Human(name), // явно викликаємо к-р  віртуального базового
        Writer("1212121"),
        Photographer("78787878", experience)
    {

        cout << "\t\tCtor Photojouranalist name : " << name << ", experience : " << experience << " year(s)" << endl;
    }
    void report()const
    {
        cout << "\n____________Reporting from _______\n\t\t" << name << " as writer and "
            << name << " as photographer" << endl;
        write();
        takePhoto();
        cout << "__________________________________\n\n";
    }
    ~Photojournalist()
    {
        cout << "\t\tDtor Photojournalist " << Human::name << endl;

    }
};

int main()
{
    Photojournalist pj("Danylo",  2);
    //будемо бачити що спрацює  1 раз конструктор класу Human
    pj.report();

    //будемо бачити що спрацює  1 раз деструктор класу Human
    return 0;
}