#define _USE_MATH_DEFINES // for M_PI
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using std::string;
// Абстрактний клас = може містити
//              поля, конструктор, деструктор, інші реалізовані методи та АБСТРАКТНІ(не реалізовані методи)
// Клас вважається абстрактним, якщо містить ХОЧ ОДНУ чисто віртуальну функцію
class Shape //abstract
{
private:
    string color;
public:
    Shape(string color = "black") : color(color) {}
    const string getColor() const { return color; }
    void setColor(const string& color)
    {
        this->color = color;
    }
    virtual double area() const abstract;  //Microsoft, Чисто віртуальний метод (функція), можна не реалізовувати, але при бажанні можна задати базову реалізацію
    virtual void display() const = 0;  // Чисто віртуальний метод, all platforms
    virtual ~Shape() {}
};

// Похідний клас Circle, стане конкретним, якщо реалізує УСІ абстрактні методи базового класу Shape
class Circle : public Shape 
{
protected:
    double radius;

public:
    explicit Circle(double r, const string & color = "black") : 
        Shape(color), radius(r) {}

    // final біля методу забороняє у похідних типах перевизначати цей метод 
    double area() const final override // похідні класи не зможуть перевизначити цей метод
    {
        return M_PI * radius * radius;
    }

    void display() const override
    {
        std::cout << "This is a circle with radius " << radius << " and " << getColor() <<" color." << std::endl;
    }
    // у класі реалізували (override ) два успадкованих абстр.методи, тому клас citcle стає конкретним
};

// Похідний класRectangle
class Rectangle final: public Shape  // final - не можна буде успадкуватисмя від цього класу
{
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override // реалізували абстрактну функцію із базового класу Shape
    {
        return width * height;
    }

    void display() const override // реалізували абстрактну функцію 
    {
        std::cout << "This is a rectangle with width " << width
            << " and height " << height << "." << std::endl;
    }
};

class Roll : public Circle
{
public:
    Roll(double radius) : Circle(radius) {}
    void display() const override
    {
        std::cout << "This is a roll with radius "  << "." << std::endl;
    }
   /* double area() const override
    {
        return 0;
    }*/

};

//class Square : public Rectangle // помилка компіляції, бл Rectangle  позначили як final
//{};


int main() {
    
    //Shape shape;// помилка : не можемо створити об'єкт абстрактного типу, але можемо використовувати посилання або вказівник на Shape
    Circle circle(1.0, "yellow"); // локальний обєкт
    Circle circle2(10.0, "blue"); // локальний обєкт
    Rectangle rectangle(4.0, 5.0); // локальний обєкт
    Roll roll(2);
    
    Shape* rectangle2 = new Rectangle(2.0, 7.0); // динамічний обєкт

    Shape* shapes[]{  &circle, &circle2, &rectangle, rectangle2 };


    for (const Shape* shape : shapes) {
        shape->display();
        std::cout << "Area: " << shape->area() << "\n\n";
    }

    delete rectangle2;
    return 0;
}
