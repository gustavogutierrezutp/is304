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

  Vector(unsigned int c, double p = 1.5) 
  {
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

  void push_back(const T &elem) 
  {
    if (sz == capacity) 
    {
      resize();
    }
    storage[sz] = elem;
    sz++;
  }

  
  
  

  void pop_back() 
  { 
    sz--; 
  }

  unsigned int size() const 
  { 
    return sz; 
  }

  unsigned int get_capacity() const 
  { 
    return capacity; 
  }




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

  T &operator[](unsigned int index) 
  { 
    return storage[index]; 
  }

  const T &operator[](unsigned int index) const 
  { 
    return storage[index]; 
  }

  T &at(unsigned int index) 
  {
    if (index >= sz) 
    {
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



//Exercise #1
int sumVector(const Vector<int>& v)
  {
    int sum = 0;
    for (unsigned int i = 0; i < v.size(); i++)
    {
        sum+=v[i];
    }

    return sum;
  }


//Exercise #2 
Vector<int> reverseVector(const Vector<int>& v)
{
    Vector<int> reversed(v.size()); 
    
    for (unsigned int i=0; i<v.size(); i++)
    {
        reversed.push_back(v[v.size() - i - 1]);
    }

    return reversed;
    
}


//Exercise #3
Vector<int> filterEven(const Vector<int>& v)
{
    Vector<int> evens;

    for (unsigned int i = 0; i < v.size(); i++)
    {
        if (v[i] % 2 == 0)
        {
            evens.push_back(v[i]);
        }
    }

    return evens;
}


//Exercise #4
void Dynamic_Growth_Test()
{
    Vector<int> test_v;
    unsigned int current_capacity = test_v.get_capacity();
    
    for (unsigned int i=0; i<1000; i++)
    {
        test_v.push_back(i);

        if (test_v.get_capacity() != current_capacity)
        {
            cout << "Capacity: " << test_v.get_capacity() << endl;
            cout << "Size: " << test_v.size() << endl;
            current_capacity = test_v.get_capacity();
            cout << endl;
        }


    }
}

//Exercise #5
Vector<int> mergeSorted(const Vector<int>& a, const Vector<int>& b)
{
    Vector<int> merged(a.size() + b.size());
    unsigned int i = 0;
    unsigned int j = 0;

    while (i<a.size() and j<b.size())
    {

        if (a[i] < b[j])
        {
            merged.push_back(a[i]);
            i++;
        }
            
        else
        {
            merged.push_back(b[j]);
            j++;
        }
        
    }


    while(j<b.size())
        {
            merged.push_back(b[j]);
            j++;
        }
    

  
    while(i<a.size())
        {
            merged.push_back(a[i]);
            i++;
        }
       

    
    return merged;
}





int main() 
{
  return 0;
}
