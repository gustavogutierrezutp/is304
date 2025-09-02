#include <iostream>
#include <vector>
using namespace std;

//### 1. **Sum of Elements**

// ── Variables globales ───────────────────────────────────────────────────────
int n;                          // Cantidad de elementos que el usuario ingresará
int valor;                      // Variable temporal para leer cada número
vector<int> u;                  // Vector global donde se guardan los números ingresados

// ── Función que suma los elementos de un vector ─────────────────────────────
int sumarvector(const vector<int> &v) { // Recibe el vector por referencia constante (no lo copia)
    int suma = 0;                  // Inicializa el acumulador en 0
    for (size_t i = 0; i < v.size(); ++i) { // Recorre índices desde 0 hasta v.size()-1 (size_t evita warnings)
        suma += v[i];              // Suma el elemento actual al acumulador
    }
    return suma;                   // Devuelve la suma total
}

// ### 2. Reverse a Vector

// ── Función que devuelve el vector invertido ────────────────────────────────
vector<int> reverseVector(const vector<int>& v) { 
    vector<int> reversed;  
    for (int i = (int)v.size() - 1; i >= 0; --i) {
        reversed.push_back(v[i]); // Insertamos el elemento v[i] al final de 'reversed'
    }
    return reversed;              // Devolvemos el vector invertido
}

// ### 3. **Filter Even Numbers**

vector<int> filterEven(const vector<int>& v) {
    vector<int> result;
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] % 2 == 0) {
            result.push_back(v[i]);
        }
    }
    return result;
}

// ── Función principal ───────────────────────────────────────────────────────
int main() {
    cout << "Ingrese la cantidad de elementos: "; // Pide al usuario cuántos números ingresará
    cin >> n;                                     // Lee la cantidad y la guarda en la variable global 'n'

    for (int i = 0; i < n; ++i) {                 // Bucle para leer 'n' valores
        cout << "Ingrese un valor: ";             // Pide un valor
        cin >> valor;                             // Lee el valor en la variable global 'valor'
        u.push_back(valor);                       // Agrega el valor al vector global 'u'
    }

    int suma = sumarvector(u);                    // Llama a la función que suma los elementos de 'u'
    cout << "La suma de los elementos es: " << suma << endl; // Muestra la suma por pantalla

    vector<int> invertido = reverseVector(u);    // Llama a la función que invierte el vector 'u'

    cout << "Vector invertido: ";                // Mensaje antes de imprimir el vector invertido
    for (size_t i = 0; i < invertido.size(); ++i) { // Recorre el vector invertido para imprimir sus elementos
        cout << invertido[i] << " ";             // Imprime cada elemento seguido de un espacio
    }
    cout << endl;

    cout << "Elementos pares: ";                // Mensaje antes de imprimir los elementos pares
    vector<int> pares = filterEven(u);         // Filtra los elementos pares
    for (size_t i = 0; i < pares.size(); ++i) { // Recorre el vector de elementos pares
        cout << pares[i] << " ";                // Imprime cada elemento seguido de un espacio
    }
    cout << endl;// Salto de línea final

    return 0;                                     // Fin del programa (0 = ejecución correcta)
}

/*
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

int main() {
  Vector<int> u;

  for (int i = 0; i < 10; i++) {
    u.push_back(i);
  }

  printVector(u);

  u[3] = 100;

  printVector(u);
  return 0;
}*/
