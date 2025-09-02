#include <iostream>
using namespace std;

class Vector {
private:
    int* storage;
    int sz;
    int capacity;

public:
    Vector(int c) {
        storage = new int[c];
        sz = 0;
        capacity = c;
    }

    ~Vector() {
        delete[] storage;
    }

    void push_back(int elem) {
        if (sz < capacity) {
            storage[sz++] = elem;
        }
    }

    int size() const {
        return sz;
    }

    int operator[](int i) const {
        return storage[i];
    }
};

Vector filterEven(const Vector& v) {
    Vector result(v.size()); 
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] % 2 == 0) {
            result.push_back(v[i]);
        }
    }
    return result;
}

int main() {
    Vector original(5);
    original.push_back(10);
    original.push_back(12);
    original.push_back(15);
    original.push_back(18);
    original.push_back(21);

    cout << "Vector Original: ";
    for (int i = 0; i < original.size(); ++i) {
        cout << original[i] << " ";
    }
    cout << endl;

    Vector pares = filterEven(original);

    cout << "Vector con Pares: ";
    for (int i = 0; i < pares.size(); ++i) {
        cout << pares[i] << " ";
    }
    cout << endl;

    return 0;
}