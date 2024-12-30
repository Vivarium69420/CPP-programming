#include <iostream>
using namespace std;

class Base {
public:
  virtual void hello() { cout << "Hello from Base class" << endl; }
};

class Derived : public Base {
public:
  void hello() override { cout << "Hello from Derived class" << endl; }
};

int main() {
  Base *base_ptr;
  Base base_object;
  Derived derived_object;

  base_ptr = &base_object;
  base_ptr->hello();

  base_ptr = &derived_object;
  base_ptr->hello();
  return 0;
}
