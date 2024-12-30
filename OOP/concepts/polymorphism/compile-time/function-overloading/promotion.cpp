#include <iostream>
using namespace std;

class Print {
 public:
  void foo(double x) { cout << "foo(double)" << endl; }

  void foo(int x) { cout << "foo(int)" << endl; }
};

int main() {
  Print obj;
  obj.foo('A');    // 'A' (char) is promoted to int, calls foo(int)
  obj.foo(3.14f);  // 3.14f is promoted to double, calls foo(double)
}
