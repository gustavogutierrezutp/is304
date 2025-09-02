#include <iostream>
#include "vector.t"

using namespace std;

Vector<int> reverseVector(const Vector<int>& v) {
    Vector<int> newVector;
    for (int i = v.size() - 1; i >= 0; i--) {
        newVector.push_back(v[i]);
    }
    return newVector;
}

int main() {
    Vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(5);

    cout << "Original vector: ";
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    Vector<int> reversedNumbers = reverseVector(numbers);

    cout << "Reversed vector: ";
    for (int i = 0; i < reversedNumbers.size(); i++) {
        cout << reversedNumbers[i] << " ";
    }
    cout << endl;

    return 0;
}
