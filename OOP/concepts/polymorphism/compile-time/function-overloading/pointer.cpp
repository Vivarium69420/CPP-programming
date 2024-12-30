#include <iostream>
using namespace std;

class Print {
 public:
  void foo(int* x) { cout << "foo(int*)" << endl; }

  void foo(double* x) { cout << "foo(double*)" << endl; }
};

int main() {
  Print obj;
  int a = 10;
  double b = 20.0;
  obj.foo(&a);
  obj.foo(&b);
}
