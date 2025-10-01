#include "bst.hh"
#include "stringUtil.hh"
#include <iostream>
#include <string>

using namespace std;

int main() {
  cout << "Hello, BST!" << endl;
  BST<string, unsigned int> ages;
  for (int i = 0; i < 1000000; ++i) {
    string name = generateRandomString(15);
    unsigned int age = rand() % 100;
    ages.insert(name, age);
    //cout << "Inserted: " << name << " with age " << age << endl;
  }
  cout << "Total entries in BST: " << ages.size() << endl;
  return 0;
}