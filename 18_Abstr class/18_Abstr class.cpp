#define _USE_MATH_DEFINES // for M_PI
#include <iostream>
#include <cmath>
#include <vector>
// Абстрактний клас = може містити
//              поля, конструктор, деструктор, інші реалізовані методи та АБСТРАКТНІ(не реалізовані методи)
// Клас вважається абстрактним, якщо містить ХОЧ ОДНУ чисто віртуальну функцію
class Shape 
{
public:
    virtual double area() const abstract;  //Microsoft, Чисто віртуальний метод (функція), можна не реалізовувати, але при бажанні можна задати базову реалізацію
    virtual void display() const = 0;  // Чисто віртуальний метод, all platforms
};

// Похідний клас Circle, стане конкретним, якщо реалізує УСІ абстрактні методи базового класу Shape
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const final override // похідні класи не зможуть перевизначити цей метод
    {
        return M_PI * radius * radius;
    }

    void display() const override
    {
        std::cout << "This is a circle with radius " << radius << "." << std::endl;
    }
};

// Похідний класRectangle
class Rectangle final: public Shape  // final - не можна буде успадкуватисмя від цього класу
{
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override
    {
        return width * height;
    }

    void display() const override 
    {
        std::cout << "This is a rectangle with width " << width
            << " and height " << height << "." << std::endl;
    }
};

class Roll : public Circle
{
public:
    void display() const override
    {
        std::cout << "This is a roll with radius "  << "." << std::endl;
    }
  /*  double area() const override
    {
        return 0;
    }*/

};

//class Square : public Rectangle
//{};


int main() {
    
    //Shape shape;// помилка : не можемо створити об'єкт абстрактного типу, але можемо використовувати посилання або вказівник на Shape
    Circle circle(1.0);
    Circle circle2(10.0);
    Rectangle rectangle(4.0, 5.0);
    
    Shape* rectangle2 = new Rectangle(2.0, 7.0);

    Shape* shapes[]{  &circle, &circle2, &rectangle, rectangle2 };


    for (const Shape* shape : shapes) {
        shape->display();
        std::cout << "Area: " << shape->area() << "\n\n";
    }

    return 0;
}
