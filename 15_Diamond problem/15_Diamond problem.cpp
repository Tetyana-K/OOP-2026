// Multi inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

// Базовий  Human
class Human
{
protected:
    string name;
public:
    Human(const string& name)
        : name(name)
    {
        cout << "\t\t!!! Ctor Human " << name << endl;
    }
    ~Human()
    {
        cout << "\t\t!!! Dtor Human " << name << endl;
    }
};
// Writer - похідний клас, успадковує поле name від Human
class Writer : public Human
{
protected:
    Writer(const string& name)
        : Human(name)
    {
        cout << "\t\tCtor Writer " << name << endl;
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
class Photographer: public Human
{
protected:
    int experience;

public:
    Photographer(const string &  name="Noname", int experience = 1)
        : Human(name), experience(experience)
    {
        cout << "\t\tCtor Photographer " << name << " with  experience of " << experience << " year(s)" << endl;
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

// Клас Photojournalist, який успадковує властивості від Writer і Photographer(двічі успадкує поле name) 
// міститиме дві версії поля name
// У клас Клас Photojournalist зайшло ДВА екземпляри Human, Diamond Problem (проблема ромба, діаманта)
class Photojournalist : public Writer, public Photographer
{
public:
    Photojournalist(const string& name = "Noname",const string namePh="Photographer", int experience = 1)
        : Writer(name), Photographer(namePh, experience)
    {

        cout << "\t\tCtor Photojouranalist name : " << name << ", experience : " << experience << " year(s)" << endl;
    }
    void report()const
    {
        //cout << name; // помилка компіляції, неоднозначне звертання, бо полів name успадкували ДВА  
        cout << "\n____________Reporting from _______\n\t\t" << Writer::name << " as writer and " // мусимо пояснити яке з полів хочемо використати
            << Photographer::name  << " as photographer"<< endl;
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
    Photojournalist pj("Danylo", "Dan", 2);
     //будемо бачити що спрацює  2 рази конструктор класу Human
    pj.report();

     //будемо бачити що спрацює  2 рази деструктор класу Human
    return 0;
}