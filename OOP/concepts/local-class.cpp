#include <iostream>

#define PI 3.14
using namespace std;

void localClass() {
  double x = 10.0;
  class Circle {
  private:
    double radius;

  public:
    Circle(double radius) {
      cout << "Circle created with radius of: " << radius << endl;
    };
    double getRadius() const { return radius; }
    double getArea() const { return (PI * radius * radius); }
    double getPerimeter() const { return (2 * PI * radius); }
    void setRadius(double value) { radius = value; }
  };

  cout << "Circle 1: " << endl;
  Circle circle1(x);
  cout << "Radius: " << circle1.getRadius() << endl;
  cout << "Area: " << circle1.getArea() << endl;
  cout << "Perimeter: " << circle1.getPerimeter() << endl;
}

int main(int argc, char *argv[]) {
  localClass();
  return 0;
}
