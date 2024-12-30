#include <iostream>
using namespace std;

class Print {
 public:
  void display(double d) { printf("Double: %.1f\n", d); }
};

int main() {
  Print obj;
  obj.display(10);  // Implicit conversion: int -> double
                    // Call display(double)
  return 0;
}