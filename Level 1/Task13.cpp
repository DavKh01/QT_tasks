#include <iostream>
#define PI 3.14159
class Shape {
public:
    double calculate_area() const {
        return 0;
    }
};

class Circle : public Shape {
public:
    Circle(double radius) : m_radius(radius) {}

    double calculate_area() const {
        return PI * m_radius * m_radius;
    }

private:
    double m_radius;
};

class Rectangle : public Shape {
public:
    Rectangle(double length, double width) : m_length(length), m_width(width) {}

    double calculate_area() const {
        return m_length * m_width;
    }

private:
    double m_length;
    double m_width;
};

int main() {
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

    std::cout << "Area of circle: " << circle.calculate_area() << std::endl;
    std::cout << "Area of rectangle: " << rectangle.calculate_area() << std::endl;

    return 0;
}
