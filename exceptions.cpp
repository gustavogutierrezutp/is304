#include <iostream>

using namespace std;

int max(int a, int b) {
    if (a == b) {
        exit(1);
        throw "Not implemented yet max" ;
    }
    return (a > b) ? a : b;
}

int main() {
    cout << "Hello, World!" << endl;
    int a = 5, b = 5;
    try {
        cout << "Max of " << a << " and " << b << " is " << max(a, b) << endl;
    } catch (const char* msg) {
        //cerr << "Error: " << msg << endl;
    }
    cout << "al final" << endl;
    return 0;
}