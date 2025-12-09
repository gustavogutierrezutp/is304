#include <iostream>

using namespace std;

template <typename T> class Vector {
private:
  // Stores the elements of the vector
  T *storage;
  // Current number of elements in the vector
  unsigned int sz;
  // Maximum number of elements that storage can hold
  unsigned int capacity;
  // Policy for resizing the vector
  double policy;

public:
  Vector() {
    storage = new T[5];
    sz = 0;
    capacity = 5;
    policy = 1.5;
  }

  Vector(unsigned int c, double p = 1.5) {
    storage = new T[c];
    sz = 0;
    capacity = c;
    policy = p;
  }

  Vector(const Vector<T> &other) {
    sz = other.size();
    capacity = other.capacity;
    policy = other.policy;
    storage = new T[capacity];
    for (unsigned int i = 0; i < sz; i++) {
      storage[i] = other.storage[i];
    }
  }

  ~Vector() { delete[] storage; }

  void push_back(const T &elem) {
    if (sz == capacity) {
      resize();
    }
    storage[sz] = elem;
    sz++;
  }

  void push_back(const Vector<T> &other) {
    reserve(sz + other.size());
    for (unsigned int i = 0; i < other.size(); i++) {
      push_back(other.storage[i]);
    }
  }

  void pop_back() { sz--; }

  unsigned int size() const { return sz; }
  unsigned int _capacity() const { return capacity; }

private:
  void resize() {
    capacity *= policy;
    T *new_storage = new T[capacity];
    for (unsigned int i = 0; i < sz; i++) {
      new_storage[i] = storage[i];
    }
    delete[] storage;
    storage = new_storage;
  }

  void reserve(unsigned int new_capacity) {
    if (new_capacity > capacity) {
      capacity = new_capacity;
      T *new_storage = new T[capacity];
      for (unsigned int i = 0; i < sz; i++) {
        new_storage[i] = storage[i];
      }
      delete[] storage;
      storage = new_storage;
    }
  }

public:
  void shrink_to_fit() {
    if (sz < capacity) {
      T *new_storage = new T[sz];
      for (unsigned int i = 0; i < sz; i++) {
        new_storage[i] = storage[i];
      }
      delete[] storage;
      storage = new_storage;
      capacity = sz;
    }
  }

  T &operator[](unsigned int index) { return storage[index]; }

  const T &operator[](unsigned int index) const { return storage[index]; }

  T &at(unsigned int index) {
    if (index >= sz) {
      throw out_of_range("Index out of range");
    }
    return storage[index];
  }

  const T &at(unsigned int index) const {
    if (index >= sz) {
      throw out_of_range("Index out of range");
    }
    return storage[index];
  }
};

void printVector(const Vector<int> &v) {
  for (unsigned int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

class Point {
private:
  double x, y;

public:
  Point(double x = 0, double y = 0) : x(x), y(y) {}
};

//Practice excercises 

//1) Sum of vector elements.
int sumVector(const Vector<int> &v) {
  int sum = 0;
  for (unsigned int i = 0; i < v.size(); i++) {
    sum += v[i];
  }
  return sum;
}

//2) Reverse a vector.
Vector<int> reverseVector(const Vector<int> &v) {
  Vector<int> rev(v.size());
  for (int i = v.size() - 1; i >= 0; i--) {
    rev.push_back(v[i]);
  }
  return rev;
}

//3) Filter even elements from a vector.
Vector<int> filtereven(const Vector<int> &v){
  Vector<int> result;
  for (unsigned i = 0; i < v.size(); i++){
    if(v[i] % 2 == 0){
      result.push_back(v[i]);
    }
  }
  return result;  
}

//4) Fill a vector with values from 1 to 1000 and print size and capacity.
void fill1to1000(Vector<int> &v) {
  int old_capacity = v._capacity();
  for (int i = 1; i <= 1000; i++) {
    v.push_back(i);
    if(v._capacity() != old_capacity){
      cout << "Size: " << v.size() << ", Capacity: " << v._capacity() << endl;
      old_capacity = v._capacity();
    }
  }
}

//5) Merge two sorted vectors.
Vector<int> mergeSorted(const Vector<int> &v1, const Vector<int> &v2) {
  Vector<int> merged;
  unsigned int i = 0, j = 0;

  while (i < v1.size() && j < v2.size()) {
    if (v1[i] < v2[j]) {
      merged.push_back(v1[i]);
      i++;
    } else {
      merged.push_back(v2[j]);
      j++;
    }
  }

  while (i < v1.size()) {
    merged.push_back(v1[i]);
    i++;
  }

  while (j < v2.size()) {
    merged.push_back(v2[j]);
    j++;
  }

  return merged;
}

int main() {

  Vector<int> u;

  Vector<int> p;

  for (int i = 0; i < 10; i++) {
    u.push_back(i);
    p.push_back(i * 2);
  }
  cout << "Your vector elements are: ";
  printVector(u);

  cout << "Your vector elements sum is: " << sumVector(u) << "" << endl;

  Vector<int> reversed = reverseVector(u);
  cout << "Your vector elements reversed are: ";
  printVector(reversed);

  cout << "Even elements of your vector are: ";
  printVector(filtereven(u));

  cout << "Your merged and sorted vector is:" << endl;
  Vector<int> merged = mergeSorted(u, p);
  printVector(merged);

  fill1to1000(u);

  return 0;
}