#include <iostream>
using namespace std;

class Vector {
private:
    int* storage;           
    unsigned int sz;        
    unsigned int capacity;  
    double policy;          

    void resize() {
        capacity = capacity * policy;  
        int* new_storage = new int[capacity];

        for (unsigned int i = 0; i < sz; i++) {
            new_storage[i] = storage[i];
        }

        delete[] storage;
        storage = new_storage;
    }

public:
    Vector(unsigned int c = 1, double p = 1.5) {
        storage = new int[c];
        sz = 0;
        capacity = c;
        policy = p;
    }

    ~Vector() {
        delete[] storage;
    }

    void push_back(int elem) {
        if (sz == capacity) {
            resize();
            cout << "Size: " << sz << ", Capacity: " << capacity << endl;
        }
        storage[sz++] = elem;
    }

    int size() const {
        return sz;
    }
};

int main() {
    Vector u(5);  

    for (int i = 1; i <= 1000; i++) {
        u.push_back(i);
    }

    return 0;
}