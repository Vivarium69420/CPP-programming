#include <iostream>
using namespace std;

class Lamp {
 public:
  void connect() { cout << "The lamp is shining brightly." << endl; }
};

class Television {
 public:
  void connect() { cout << "The television is displaying a channel." << endl; }
};

// Function to connect different devices
void connectDevice(void* device, string type) {
  if (type == "Lamp") {
    static_cast<Lamp*>(device)->connect();
  } else if (type == "Television") {
    static_cast<Television*>(device)->connect();
  }
}

int main() {
  Lamp lamp;
  Television tv;

  connectDevice(&lamp, "Lamp");      // The lamp is shining brightly.
  connectDevice(&tv, "Television");  // The television is displaying a channel.

  return 0;
}
