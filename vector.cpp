/*
Names: Juan Jose Posada Arboleda and Juan Jose Mendez Lozano
Teacher: Gustavo Adolfo Gutierrez
Course: Data Structures 2025-2
Date: 09/01/2025
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

// 3. Filtrar los elementos pares de un vector
Vector<int> filterEven(const Vector<int>& v) {
    Vector<int> even;
    for (int i = 0; i < v.sizeV(); i++) {
        if (v[i] % 2 == 0) {
            even.push_back(v[i]);
        }
    }
    return even; 
}

// 5. Fusionar dos vectores ordenados
Vector<int> mergeSorted(const Vector<int>& a, const Vector<int>& b) {
    Vector<int> merged;
    int i = 0, j = 0;
    // Fusionar elementos mientras ambos vectores tengan elementos restantes
    while (i < a.sizeV() && j < b.sizeV()) {
        if (a[i] <= b[j]) {
            merged.push_back(a[i]);
            i++;
        } else {
            merged.push_back(b[j]);
            j++;
        }
    }
    // Añadiendo los elementos restantes del vector a
    while (i < a.sizeV()) {
        merged.push_back(a[i]);
        i++;
    }
    // Añadiendo los elementos restantes del vector b
    while (j < b.sizeV()) {
        merged.push_back(b[j]);
        j++;
    }
    return merged;
}

/* 
  A continuacion se presentan dos versiones del main, una con valores predeterminados y otra con entrada del usuario
  Esto con el fin de poder probar la funcion sumVector de ambas maneras ya que no se especifico como debia ser la entrada
  Se comenta cada uno de los mains para evitar conflictos al momento de compilar y ejecutar el programa, entonces quitar los comentarios para poder probar cada uno
*/

/*
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
*/

/*
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
*/

/*
//Main de prueba ejercicio 3 con valores predeterminados
int main(){
    Vector<int> u;
    for(int i = 0; i < 14; i++){
        u.push_back(i+3);
    }
    Vector<int> even = filterEven(u);
    cout << "Los numeros pares son: ";
    for (int i = 0; i < even.sizeV(); i++) {
        cout << even[i] << " ";
    }
    cout << endl << endl;
}
// Main de prueba ejercicio 3 con entrada del usuario
int main(){
    int n; cout << "Ingrese tamaño del vector: "; cin >> n;
    Vector<int> v;
    cout << "Ingrese " << n << " numeros: ";
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    Vector<int> pares = filterEven(v);
    cout << "Pares: ";
    for (int i = 0; i < pares.sizeV(); i++) cout << pares[i] << " ";
    cout << endl;
}
*/

/*
//Main de prueba ejercicio 4 con valores predeterminados 
// (No se puede hacer por la entrada del usuario ya que el ejercicio es mas como un test de impresion de la capacidad dinamica del vector)
// Este ejercicio es un crecimiento dinamico del vector y se imprime su tamaño y capacidad cada vez que esta cambia
int main() {
    Vector<int> u;
    int oldCap = u.getCapacity();

    for (int i=1; i<=1000; i++) {
        u.push_back(i);
        if (u.getCapacity() != oldCap) {
            cout << "Size: " << u.sizeV()
                 << ", Capacity: " << u.getCapacity() << endl;
            oldCap = u.getCapacity();
        }
    }
}
*/

/*
//Main de prueba ejercicio 5
int main(){
    Vector<int> a, b;
    // Create first sorted vector
    for(int i = 0; i < 14 ; i++){
        a.push_back(1 + i*2);
    }
    // Create second sorted vector
    for(int i = 0; i < 14 ; i++){
        b.push_back(2 + i*2);
    }
    Vector<int> merged = mergeSorted(a, b);
    cout << "Vector merged: ";
    for (int i = 0; i < merged.sizeV(); i++) {
        cout << merged[i] << " ";
    }
    cout << endl;
    return 0;
}
//Main de prueba ejercicio 5 con entrada del usuario (Salvedad: se debe ingresar los numeros ordenados)
int main(){
    int n1, n2;
    cout << "Tamano vector A: "; cin >> n1;
    Vector<int> a;
    cout << "Ingrese " << n1 << " numeros ORDENADOS: ";
    for (int i = 0; i < n1; i++) { int x; cin >> x; a.push_back(x); }
    cout << "Tamano vector B: "; cin >> n2;
    Vector<int> b;
    cout << "Ingrese " << n2 << " numeros ORDENADOS: ";
    for (int i = 0; i < n2; i++) { int x; cin >> x; b.push_back(x); }
    Vector<int> merged = mergeSorted(a, b);
    cout << "Merge: ";
    for (int i = 0; i < merged.sizeV(); i++) cout << merged[i] << " ";
    cout << endl;
}
*/