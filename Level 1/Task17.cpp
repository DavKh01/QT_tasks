#include <iostream>
#define PI 3.14159
class Shape {
public:
	virtual double area() const = 0;
};

class Circle : Shape {

public:
	Circle(double radius) {
		if (radius > 0) {
			m_radius = radius;
		}
		else {
			throw std::invalid_argument("inavalid input");
		}
	}
	double area() const override {
		return PI * m_radius * m_radius;
	}

private:
	double m_radius;
};

class Rectangle : Shape {
public:
	Rectangle(double length, double width) {
		if (length > 0 && width > 0) {
			m_length = length;
			m_width = width;
		}
		else {
			throw std::invalid_argument("inavalid input");
		}
	}
	double area() const override {
		return m_width * m_length;
	}
private:
	double m_width;
	double m_length;
};

int main() {
	Circle circle(5.0);
	Rectangle rectangle(4.0, 6.0);

	std::cout << "Area of circle: " << circle.area() << std::endl;
	std::cout << "Area of rectangle: " << rectangle.area() << std::endl;

	return 0;
}