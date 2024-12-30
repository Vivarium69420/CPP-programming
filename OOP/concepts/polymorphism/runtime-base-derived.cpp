#include <iostream>
#include <string>

using namespace std;

class Base {
 public:
  void print() { cout << "Base" << endl; }
};

class Derived : public Base {
 public:
  void print() { cout << "Derived" << endl; }
};

int main() {
  Base *ptr = new Base();
  ptr->print();  // Output: Base
  delete ptr;

  ptr = new Derived();
  ptr->print();  // Output: Derived
  delete ptr;

  return 0;
}