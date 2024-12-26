#include <iostream>
using namespace std;

class Print {
public:
  void display(int i) { cout << "Integer: " << i << endl; }

  void display(double d) { cout << "Double: " << d << endl; }

  void display(string s) { cout << "String: " << s << endl; }
};

int main() {
  Print obj;
  obj.display(10);      // Calls display(int)
  obj.display(3.14);    // Calls display(double)
  obj.display("Hello"); // Calls display(string)
  return 0;
}
