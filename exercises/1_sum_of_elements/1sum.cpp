#include <iostream>
#include "vector.t"
using namespace std;

int sumVector(const Vector<int>& v) {
    int sum = 0;
    for (unsigned int i = 0; i < v.size(); i++) {
        sum = sum + v[i];
    }
    return sum;
}

int main() {
    Vector<int> numbers;
    numbers.push_back(2);
    numbers.push_back(4);
    numbers.push_back(6);
    numbers.push_back(8);

    int result = sumVector(numbers);
    cout << "The sum of the elements is: " << result << endl;
    return 0;
}
