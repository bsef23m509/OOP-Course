#include <iostream>
using namespace std;

#define PIE  \
    {        \
        3.14 \
    }

class Shape
{
public:
    virtual double area() = 0;
};

class Circle : public Shape
{
protected:
    double radius;

public:
    Circle()
    {
        this->radius = 0.0;
    }

    Circle(double radius)
    {
        this->radius = radius;
    }

    double area()
    {
        double area = PIE;
        area *= (this->radius * this->radius);
        return area;
    }
};

class Rectangle : public Shape
{
protected:
    double length;
    double width;

public:
    Rectangle()
    {
        this->length = 0.0;
        this->width = 0.0;
    }

    Rectangle(double length, double width)
    {
        this->length = length;
        this->width = width;
    }

    double area()
    {
        double area = (this->length * this->width);
        return area;
    }
};

class ShapeAreaCalculator : public Circle, public Rectangle
{
public:
    ShapeAreaCalculator() {}

    ShapeAreaCalculator(double radius, double length, double width)
        : Circle(radius),
          Rectangle(length, width) {}

    double totalArea()
    {
        double area = this->Circle::area() + this->Rectangle::area();
        return area;
    }
};

int main()
{

    Circle c1(10.0);
    Rectangle r1(10.0, 10.0);
    ShapeAreaCalculator s1(10.0, 10.0, 10.0);

    cout << "Circle area: " << c1.area() << endl;
    cout << "Rectangle area: " << r1.area() << endl;
    cout << "Combined area: " << s1.totalArea() << endl;

    return 0;
}