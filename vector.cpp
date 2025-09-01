#include <iostream>

using namespace std;

template <typename T>
class Vector
{
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
  Vector()
  {
    storage = new T[5];
    sz = 0;
    capacity = 5;
    policy = 1.5;
  }

  Vector(unsigned int c, double p = 1.5)
  {
    storage = new T[c];
    sz = 0;
    capacity = c;
    policy = p;
  }

  Vector(const Vector<T> &other)
  {
    sz = other.size();
    capacity = other.capacity;
    policy = other.policy;
    storage = new T[capacity];
    for (unsigned int i = 0; i < sz; i++)
    {
      storage[i] = other.storage[i];
    }
  }

  ~Vector() { delete[] storage; }

  void push_back(const T &elem)
  {
    if (sz == capacity)
    {
      resize();
    }
    storage[sz] = elem;
    sz++;
  }

  void push_back(const Vector<T> &other)
  {
    reserve(sz + other.size());
    for (unsigned int i = 0; i < other.size(); i++)
    {
      push_back(other.storage[i]);
    }
  }

  void pop_back() { sz--; }

  unsigned int size() const { return sz; }

private:
  void resize()
  {
    capacity *= policy;
    T *new_storage = new T[capacity];
    for (unsigned int i = 0; i < sz; i++)
    {
      new_storage[i] = storage[i];
    }
    delete[] storage;
    storage = new_storage;
  }

  void reserve(unsigned int new_capacity)
  {
    if (new_capacity > capacity)
    {
      capacity = new_capacity;
      T *new_storage = new T[capacity];
      for (unsigned int i = 0; i < sz; i++)
      {
        new_storage[i] = storage[i];
      }
      delete[] storage;
      storage = new_storage;
    }
  }

public:
  void shrink_to_fit()
  {
    if (sz < capacity)
    {
      T *new_storage = new T[sz];
      for (unsigned int i = 0; i < sz; i++)
      {
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

  const T &at(unsigned int index) const
  {
    if (index >= sz)
    {
      throw out_of_range("Index out of range");
    }
    return storage[index];
  }
};

void printVector(const Vector<int> &v)
{
  for (unsigned int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int vectorSum(const Vector<int> &u)
{
  int sum;
  sum = 0;
  for (int i = 0; i < u.size(); i++)
  {
    sum += u[i];
  }
  return sum;
}

Vector<int> reverseVector(const Vector<int>& u)
{
  if (u.size() == 0)
  {
    return u;
  }
  int limit;
  limit = u.size() - 1;
  Vector<int> w;
  for (int i = 0; i < (limit + 1); i++)
  {
    w.push_back(u[limit - i]);
  }
  return w;
}

Vector<int> filterEven(const Vector<int>& u){
  if (u.size() == 0){
    return u;
  }
  int limit;
  limit = u.size();
  Vector<int> w;
  for (int i = 0; i < limit; i ++){
    if (u[i] % 2 == 0){
      w.push_back(u[i]);
    }
  }
  return w;
}

Vector<int> mergeSorted(const Vector<int>& a, const Vector<int>& b){
  if (a.size() == 0){
    return b;
  } else if (b.size() == 0) {
    return a;
  }
  Vector<int> w;
  for (int i = 0; i < a.size(); i ++){
    w.push_back(a[i]);
  }
  for (int i = 0; i < b.size(); i ++){
    w.push_back(b[i]);
  }
  for (int i = 0; i < w.size(); i ++){
    for (int j = 0; j < w.size() - i - 1; j++ ){
        if(w[j] > w[j+1]){
          int bridge;
          bridge = w[j];
          w[j] = w[j+1];
          w[j+1] = bridge;
        }
    }
  }
  return w;
}

int main()
{
  Vector<int> u;
for (int i = 0; i < 10; i++)
{
  u.push_back(i);
}
  Vector<int> v(u);
  Vector<int> y(mergeSorted(u, v));
  printVector(y);
  return 0;
}
