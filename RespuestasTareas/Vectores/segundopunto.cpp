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

Vector reverseVector(const Vector& v) {
    Vector result(v.size());
    for (int i = v.size() - 1; i >= 0; --i) {
        result.push_back(v[i]);
    }
    return result;
}

int main() {
    Vector original(3);
    original.push_back(10);
    original.push_back(20);
    original.push_back(30);

    cout << "Vector Original: ";
    for (int i = 0; i < original.size(); ++i) {
        cout << original[i] << " ";
    }
    cout << endl;

    Vector invertido = reverseVector(original);

    cout << "Vector Invertido: ";
    for (int i = 0; i < invertido.size(); ++i) {
        cout << invertido[i] << " ";
    }
    cout << endl;

    return 0;
}