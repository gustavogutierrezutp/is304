/*
Names: Juan Jose Posada Arboleda and Juan Jose Mendez Lozano
Teacher: Gustavo Adolfo Gutierrez
Course: Data Structures 2025-2
Date: 08/31/2025
Description: This code implements a Vector class in C++ with basic functionalities like size, push_back, and element access.
    It also include fifth functions that operate on Vector<int>: Sumatory of elements, Reverse the vector, Filter even elements, dynamic growth test and merge two sorted vectors.
*/

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
  int sizeV() const { return sz; }
  int getCapacity() const {
        return capacity;
    }
};

// 1. Función que suma elementos de un Vector<int>
int sumVector(const Vector<int>& v) {
    int suma = 0;
    for (int i = 0; i < v.sizeV(); i++) {
        suma += v[i];
    }
    return suma;
}

// 2. Sacar el reverso de un vector
Vector<int> reverseVector(const Vector<int>& v) {
    Vector<int> reversed;
    for (int i = v.sizeV() - 1; i >= 0; i--) {
        reversed.push_back(v[i]);
    }
    return reversed;
}

//  A continuacion se presentan dos versiones del main, una con valores predeterminados y otra con entrada del usuario
// Esto con el fin de poder probar la funcion sumVector de ambas maneras ya que no se especifico como debia ser la entrada

// Main de prueba ejercicio 1 con valores predeterminados
int main(){
    Vector<int> u;
    for(int i = 0; i < 15; i++){
        u.push_back(i+2);
    }
    cout << "La suma es: " << sumVector(u) << endl;
    return 0;
}
//Main de prueba ejercicio 1 con entrada del usuario
int main(){
    int n; cout << "Ingrese tamaño del vector: "; cin >> n;
    Vector<int> v;
    cout << "Ingrese " << n << " numeros: ";
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    cout << "La suma es: " << sumVector(v) << endl;
}

//Main de prueba ejercicio 2 con valores predeterminados
int main(){
    Vector<int> l;
    for(int i = 0; i < 15; i++){
        l.push_back(i+5);
    }
    Vector<int> reverse = reverseVector(l);
    cout << "El vector invertido es: ";
    for (int i = 0; i < reverse.sizeV(); i++) {
        cout << reverse[i] << " ";
    }
    cout << endl;
    return 0;
}
// Main de prueba ejercicio 2 con entrada del usuario
int main(){
    int n; cout << "Ingrese tamaño del vector: "; cin >> n;
    Vector<int> v;
    cout << "Ingrese " << n << " numeros: ";
    for (int i = 0; i < n; i++) {
      int x; cin >> x;
      v.push_back(x);
    }
    Vector<int> r = reverseVector(v);
    cout << "Invertido: ";
    for (int i = 0; i < r.sizeV(); i++) cout << r[i] << " ";
    cout << endl;
}