#include <iostream>
using namespace std;

class Point {
private:
  int x, y;

public:
  Point(int x = 0, int y = 0) : x(x), y(y) {}

  // Overload the '+' operator
  Point operator+(const Point &other) {
    return Point(x + other.x, y + other.y);
  }

  // Overload the '-' operator
  Point operator-(const Point &other) {
    return Point(x - other.x, y - other.y);
  }

  // Overload the '<<' operator
  Point operator<<(const Point &other) {
    return Point(x << other.x, y << other.y);
  }

  void display() { cout << "(" << x << ", " << y << ")" << endl; }
};

int main() {
  Point p1(3, 4), p2(1, 2);
  Point p3 = p1 + p2; // Calls overloaded '+'
  p3.display();       // Output: (4, 6)

  Point p4 = p1 - p2; // Calls overloaded '-'
  p4.display();       // Output: (2, 2)

  Point p5 = p1 << p2; // Calls overloaded '<<'
  p5.display();        // Output: (3, 16)

  return 0;
}
