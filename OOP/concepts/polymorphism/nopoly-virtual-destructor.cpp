#include <iostream>
using namespace std;

class Base {
 public:
  ~Base() {  // Non-virtual destructor
    cout << "Base destructor called" << endl;
  }
};

class Derived : public Base {
 public:
  ~Derived() {  // Destructor for Derived
    cout << "Derived destructor called" << endl;
  }
};

int main() {
  Base* ptr = new Derived();
  delete ptr;

  return 0;
}
