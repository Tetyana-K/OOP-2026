// Multi inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

// Базовий клас 1: Writer
class Writer 
{
protected:
    string name;
    Writer(const string& name = "Noname")// 2 in 1
        : name(name)
    {
        cout << "\t\tCtor Writer " << name << endl;
    }
public:
    void write() const
    {
        cout << "Writing an article." << endl;
    }
    ~Writer()
    {
        cout << "\t\tDtor Writer " << name << endl;
    }
};

// Базовий клас 2: Photographer
class Photographer 
{
protected:
    
    int experience;
   

public:
    Photographer(int experience = 1)
        : experience(experience)
    {
        cout << "\t\tCtor Photographer with  experience of " << this->experience << " year(s)" << endl;
    }
    void takePhoto() const
    {
       cout << "Taking a photo." << endl;
    }
    ~Photographer()
    {
        cout << "\t\tDtor Photographer with experience " << experience << endl;

    }
};

// Клас Photojournalist, який успадковує властивості і поведінку від Writer і Photographer
class Photojournalist : public Writer, public Photographer 
{
    // успадкували name as protected &  experience as protected;
public:
   Photojournalist(const string& name = "Noname", int experience = 1)
        : Writer(name), Photographer(experience) 
    {
        
        cout << "\t\tCtor Photojouranalist name : " << this-> name <<
            " experience : " << this->experience << " year(s)" << endl;
    }
    void report()const
    {
       cout << "\n____________Reporting from " << Writer::name<<  endl;
       write();
       takePhoto();
       cout << "__________________________________\n\n";
    }
    ~Photojournalist()
    {
        cout << "\t\tDtor Photojournalist " << Writer::name << endl;
    }
};

int main() 
{
    Photojournalist pj("Danylo", 2);// PhotoJournalist---> ctor Writer, ctor  Photographer 
    pj.report();
    cout << endl;

    Writer& writer = pj;
    writer.write();

    Photographer* photographer = &pj;
    photographer->takePhoto();


    return 0;
}