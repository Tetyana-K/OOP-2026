
#include <iostream>
using namespace std;

// Interface =  абстр тип, який пропонує  ТІЛЬКИ абстрактну поведінку (методи!!!)
struct IStudy
{
    //public: 
    virtual void study() = 0; // чисто віртуальна функція (абстрактний метод)
    virtual void passExam() = 0;
};
struct INamed
{
    virtual void setName(const  string& name) = 0;
    virtual const string& getName() const = 0;

};
class Student : public IStudy, public INamed // клас Студент РЕАЛІЗУЄ інтерфейси IStudy і INamed
{
public:
    Student(const string& name = "Noname")
    {
        setName(name);
    }
    const string& getName() const // реалізація методу із  інтерфейсу INamed
    {
        return name;
    }
    void setName(const  string& name)// реалізація методу із  інтерфейсу INamed
    {
        if (name != "")
            this->name = name;
    }
    virtual void study() // реалізація методу із  інтерфейсу IStudy
    {
        cout << "Student " << name << " studies in university or colleage\n";
    }
    virtual void passExam()// реалізація методу із  інтерфейсу IStudy
    {
        cout << "Student " << name << " must pass exam!\n";
    }
    void print() const
    {
        cout << "Student name : " << name << endl;
    }
private:
    string name = "Noname";

};
struct Animal : /*public*/ INamed // для struct успадкування неявно public
{
public:

    virtual void setName(const string& name) override
    {
        if (name != "")
            this->name = name;
        else
            this->name = "Noname-animal";
    }
   virtual const string& getName() const override
    {
        return name;
    }
    Animal(const  string& name)
    {
        setName(name);
    }
private:
    string  name;
    
};

void demo(INamed* named)
{
    cout << "Demo  func : " << named->getName() << endl;
}
class MyClass //: public INamed
{
    string name = "class";
    // Inherited via INamed
   /* virtual void setName(const string& name) override
    {
    }
    virtual const string& getName() const override
    {
        return name;
    }*/
};
int main()
{
   Student  student("Olena");
   student.passExam();

    IStudy* iptr = &student; // створили вказівник на інтерфейс, який може зберігати вказівник на будь який обєкт типу, що реалізував цей інтерфейс
    iptr->study();

    IStudy& is = student;
    is.passExam();

    INamed* pptr = &student;
    pptr->setName("Olena Kushnir");
    cout << "Student : " << pptr->getName() << endl;

    demo(&student);
    
    Animal animal("Kotyk");
    demo(&animal);

    MyClass obj;
   // demo((INamed&)obj);

}

