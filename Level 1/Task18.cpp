#include <iostream>
#define PI 3.14159
template<typename T>
class Shape {
public:
    virtual T area() const = 0;
};

template<typename T>
class Rectangle : public Shape<T> {
private:
    T width;
    T height;
public:
    Rectangle(T w, T h) : width(w), height(h) {}

    T area() const override {
        return width * height;
    }
};

template<typename T>
class Circle : public Shape<T> {
private:
    T radius;
public:
    Circle(T r) : radius(r) {}

    T area() const override {
        return PI * radius * radius;
    }
};

int main() {
    Rectangle<int> rect(5, 4);
    Circle<float> circle(3.5);

    std::cout << "Area of Rectangle: " << rect.area() << std::endl;
    std::cout << "Area of Circle: " << circle.area() << std::endl;

    return 0;
}
