#include <iostream>

using namespace std;
template <typename T> bool isSmaller(T first, T second) {
  if (first > second)
    return true;
  else
    return false;
}

int main(int argc, char *argv[]) {
  bool result = isSmaller<int>(4, 5);
  cout << result << endl;

  return 0;
}
