#include <iostream>
using namespace std;

class Point {
 private:
  int x, y;

 public:
  Point(int x = 0, int y = 0) : x(x), y(y) {}

  // Member function
  Point operator-(const Point &p1) { return Point(x + p1.x, y + p1.y); }

  // Non member function
  friend Point operator+(const Point &p1, const Point &p2) {
    return Point(p1.x + p2.x, p1.y + p2.y);
  }
  void display() const { cout << "(" << x << ", " << y << ")" << endl; }
};

int main() {
  Point p1(1, 2);
  Point p2(3, 4);
  Point p3 = p1 - p2;

  p3.display();  // Output: (4, 6)

  return 0;
}