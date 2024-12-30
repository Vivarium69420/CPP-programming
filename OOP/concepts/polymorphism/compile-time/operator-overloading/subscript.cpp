#include <iostream>
using namespace std;

class Array {
 private:
  int *ptr;
  int size;

 public:
  Array(int s) : size(s) { ptr = new int[size]; };
  int &operator[](int index) {
    if (index < 0 || index >= size) {
      cerr << "Index out of range" << endl;
      exit(EXIT_FAILURE);
    }
    return ptr[index];
  }
  ~Array() { delete[] ptr; }
};

int main(int argc, char *argv[]) {
  Array arr(3);
  arr[0] = 100;
  arr[1] = 100;
  arr[2] = 100;

  for (int i = 0; i < 5; i++) {
    cout << "Value at i: " << arr[i] << endl;
  }

  return 0;
}