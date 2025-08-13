#include <iostream>

using namespace std;

int main() {
  int x = 10;
  int *p = &x; // Pointer to x

  cout << "Value of x: " << x << endl;                  // Output: 10
  cout << "Address of x: " << &x << endl;               // Output: Address of x
  cout << "Value at pointer p: " << *p << endl;         // Output: 10
  cout << "Address stored in pointer p: " << p << endl; // Output: Address of x

  *p = 20; // Change value at pointer p

  cout << "New value of x: " << x << endl; // Output: 20
  return 0;
}