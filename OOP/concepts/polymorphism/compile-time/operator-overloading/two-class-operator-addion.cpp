#include <iostream>
using namespace std;

class Point1 {
public:
  int x, y, z;
  Point1(int x = 0, int y = 0) : x(x), y(y) {}
};

class Point2 {
public:
  int x, y;
  Point2(int x = 0, int y = 0) : x(x), y(y) {}

  Point2 operator+(const Point1 &p1) { return Point2(x + p1.x, y + p1.y); }

  Point2 operator+(int i) { return Point2(x + i, y + i); }
  void display() { cout << "(" << x << ", " << y << ")" << endl; }
};

int main(int argc, char *argv[]) {
  Point1 p1(1, 2);
  Point2 p2(3, 4);

  Point2 p3 = p2 + p1;
  p3.display();

  Point2 p4 = p2 + 5;
  p4.display();

  return 0;
}
