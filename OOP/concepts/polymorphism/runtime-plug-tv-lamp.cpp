#include <iostream>
using namespace std;

// Base class
class Plug {
public:
  // virtual void connect() { cout << "Generic plug." << endl; }
  virtual void connect() = 0;

  // Virtual destructor to ensure proper cleanup of derived classes
  virtual ~Plug() {}
};

// Derived class: Lamp
class Lamp : public Plug {
public:
  void connect() override { // Override the base class function
    cout << "The lamp is shining brightly." << endl;
  }
};

// Derived class: Television
class Television : public Plug {
public:
  void connect() override { // Override the base class function
    cout << "The television is displaying a channel." << endl;
  }
};

// Demonstrate polymorphism
int main() {
  Plug *base_ptr; // Base class pointer

  // Create a Lamp object
  Lamp lamp;
  lamp.connect();
  base_ptr = &lamp;
  base_ptr->connect(); // Calls Lamp's connect

  // Create a Television object
  Television tv;
  base_ptr = &tv;
  base_ptr->connect(); // Calls Television's connect

  return 0;
}
