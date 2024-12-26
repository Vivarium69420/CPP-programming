#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class Vector {
 private:
  T *data;
  size_t sz;
  size_t cap;

 public:
  void reallocate(size_t new_capacity);
  Vector();
  ~Vector();

  // Capacity
  size_t size() const;
  size_t capacity() const;
  void shrink_to_fit();

  // Element Access
  T &at(size_t index);

  // Modifiers
  void push_back(const T &value);
  void pop_back();
  void insert(size_t index, const T &value);
  void erase(size_t index);
};

template <typename T>
Vector<T>::Vector() : sz(0), cap(1) {
  data = new T[cap];
}

template <typename T>
Vector<T>::~Vector() {
  delete[] data;
}

template <typename T>
size_t Vector<T>::size() const {
  return sz;
}

template <typename T>
size_t Vector<T>::capacity() const {
  return cap;
}

template <typename T>
void Vector<T>::reallocate(size_t new_capacity) {
  T *new_data = new T[new_capacity];
  for (size_t i = 0; i < sz; i++) new_data[i] = data[i];

  delete[] data;
  data = new_data;
  cap = new_capacity;
}

template <typename T>
T &Vector<T>::at(size_t index) {
  return data[index];
}

template <typename T>
void Vector<T>::push_back(const T &value) {
  if (sz == cap) {
    reallocate(cap * 2);
  }
  data[sz++] = value;
}

template <typename T>
void Vector<T>::pop_back() {
  if (sz > 0) {
    sz--;
    if (sz <= cap / 4) {
      reallocate(cap / 2);
    }
  }
}

template <typename T>
void Vector<T>::insert(size_t index, const T &value) {
  if (index > sz) {
    cout << "Index out of range" << endl;
    exit(EXIT_FAILURE);
  }

  if (sz == cap) {
    reallocate(cap * 2);
  }

  for (size_t i = sz; i > index; --i) {
    data[i] = data[i - 1];
  }

  data[index] = value;
  ++sz;
}

template <typename T>
void Vector<T>::erase(size_t index) {
  if (index >= sz) {
    cout << "Index out of range" << endl;
    exit(EXIT_FAILURE);
  }

  // Just copy by one element ahead
  for (size_t i = index; i < sz - 1; ++i) {
    data[i] = data[i + 1];
  }

  --sz;
}

int main(int argc, char *argv[]) {
  Vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.pop_back();

  v.insert(2, 5);
  v.push_back(6);

  for (size_t i = 0; i < v.size(); i++) cout << v.at(i) << " ";
  cout << endl;

  v.erase(3);

  for (size_t i = 0; i < v.size(); i++) cout << v.at(i) << " ";
  cout << endl;

  return 0;
}