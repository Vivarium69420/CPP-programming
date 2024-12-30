#include <iostream>

#define PI 3.14

using namespace std;
class Circle {
private:
  double radius;

public:
  double getRadius() const;
  double getArea() const;
  double getPerimeter() const;
  void setRadius(double value);
};

double Circle::getRadius() const { return radius; }

double Circle::getPerimeter() const { return (2 * PI * radius); }

double Circle::getArea() const { return (PI * radius * radius); }

void Circle::setRadius(double value) { radius = value; }

int main() {
  cout << "Circle 1: " << endl;
  Circle circle1;
  circle1.setRadius(10.0);
  cout << "Radius: " << circle1.getRadius() << endl;
  cout << "Area: " << circle1.getArea() << endl;
  cout << "Perimeter: " << circle1.getPerimeter() << endl;
}
