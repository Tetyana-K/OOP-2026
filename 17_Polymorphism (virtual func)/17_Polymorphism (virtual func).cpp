#define _USE_MATH_DEFINES // for M_PI
#include <iostream>
#include <cmath>
#include <vector>


/*Поліморфізм - це один із принципів ООП, вказує на здатність об'єктів різних класів відповідати по різному на однакові запити

Два види поліморфізму :
Етапу Компіляції (ранній = раннє зв'язування імені функції з  реалізацією) поліморфізм,  статичний поліморфізм.
    Вибір функції відбувається на етапі компіляції.
    Приклади цього виду поліморфізму : перевантаження функцій і операторів, шаблони функцій.
    
Динамічний (пізній = пізнє зв'язування імені функції з  реалізацією, етап виконання) поліморфізм (true polymorphism):
    Вибір методу відбувається під час виконання програми.
    Реалізується через  віртуальні функції, які можуть бути перевизначені в похідних класах.
    Дозволяє об'єктам різних класів викликати однаково названі методи, але виконувати специфічний для їх класу код.
    Через вказівник або посилання на базовий клас будуть викликатися функції із класу ЗГІДНО ФАКТИЧНОГО ТИПУ обєкта (а не вказівника чи посилання )
    */


// Demo дин. полімофізм
// 1) успадкування (public)
// 2) virtual функція(ї)
// 3) main (або клієнт) : працюємо через  посилання (вказівники) на базовий клас



// Базовий клас Shape
class Shape 
{
public:
    virtual double area() const 
    {
        return 0.0;
    }

    virtual void display() const 
    {
        std::cout << "This is a shape." << std::endl;
    }
   virtual ~Shape() // virtual !!!!!!!
    {
        std::cout << "\t\tDestructor ~Shape()\n";
    }
};

// Похідний клас Circle
class Circle : public Shape 
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override
    {
        return M_PI * radius * radius;
    }

    void display() const override
    {
        std::cout << "This is a circle with radius " << radius << "." << std::endl;
    }
    double length() const
    {
        return 2 * M_PI * radius;
    }
    ~Circle()
    {
        std::cout << "\t\tDestructor ~Circle() with radius " << radius << "\n";
        

    }
};

// Похідний класRectangle
class Rectangle : public Shape 
{
private:
    double width;
    double height;

public:
   Rectangle(double w, double h) : width(w), height(h) {}

   virtual double area() const override
   {
        return width * height;
    }

    void display() const override 
    {
        std::cout << "This is a rectangle with width " << width 
            << " and height " << height << "." << std::endl;
        
    }
    ~Rectangle()
    {
        std::cout << "\t\tDestructor ~Rectangle() with sides " << width << ", " << height << "\n";

    }
};

void demo(Shape& shape)
{
    shape.display();
}
int main() {
    Shape shape;
    Circle circle(1.0);
    
    Rectangle rectangle(4.0, 2.0);
    demo(rectangle);

    /*Shape& sh = circle; 
    sh.display();
    std::cout << "Area sh = " << sh.area() << "\n\n";*/

    //Shape* shR = &rectangle; //
    //shR->display();
    //std::cout << "Area sh2 = " << shR->area() << "\n";
   
    //Shape* shapes[]{ &shape, &circle, &rectangle };
    
  /*  int menu;
    Shape* shape_;
    std::cin >> menu;
    if (menu == 1)
        shape_ = new Circle(5);*/

    std::cout << "\nArray of shapes\n";
    //int i = 0;
    //for (const Shape* shape : shapes) 
    //{
    //    std::cout << ++i << " shape\n";
    //    shape->display();
    //    std::cout << "Area: " << shape->area() << "\n\n";
    //    //std::cout << "Area: " << shape->length() << "\n\n";
    //}
    //std::cout << std::endl;

    //Shape* shapes2[] { new Circle(2), new Rectangle(7,7) };
    //for (const Shape* shape : shapes2) {
    //    shape->display();
    //    std::cout << "Area: " << shape->area() << "\n";
    //    delete shape;
    //}
    std::cout << "\n\n";
    return 0;
}
