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

Vector merge(const Vector& a, const Vector& b) {
    Vector result(a.size() + b.size());  

    int i = 0, j = 0;

    for (; i < a.size() && j < b.size(); ) {
        if (a[i] <= b[j]) {
            result.push_back(a[i++]);
        } else {
            result.push_back(b[j++]);
        }
    }

    for (; i < a.size(); i++) {
        result.push_back(a[i]);
    }

    for (; j < b.size(); j++) {
        result.push_back(b[j]);
    }

    return result;
}

int main() {
    Vector v1(5);
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(7);
    v1.push_back(9);

    Vector v2(5);
    v2.push_back(2);
    v2.push_back(4);
    v2.push_back(6);
    v2.push_back(8);
    v2.push_back(10);

    cout << "Vector 1: ";
    for (int i = 0; i < v1.size(); i++) cout << v1[i] << " ";
    cout << endl;

    cout << "Vector 2: ";
    for (int i = 0; i < v2.size(); i++) cout << v2[i] << " ";
    cout << endl;

    Vector merged = merge(v1, v2);

    cout << "Vector 3: ";
    for (int i = 0; i < merged.size(); i++) cout << merged[i] << " ";
    cout << endl;

    return 0;
}