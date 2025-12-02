#include <iostream>
#include <vector>

using namespace std;

vector<int> filterEven(const vector<int>& v) {
    vector<int> evenNumbers;

    for (int i = 0; i < v.size(); i++) {
        int currentNumber = v[i];

        if (currentNumber % 2 == 0) {
            evenNumbers.push_back(currentNumber);
        }
    }

    
    return evenNumbers;
}


int main() {
    
    vector<int> myNumbers = {1, 2, 3, 4, 5, 6};

    
    vector<int> evenOnly = filterEven(myNumbers);

    
    cout << "The even numbers are: ";
    for (int i = 0; i < evenOnly.size(); i++) {
        cout << evenOnly[i] << " "; 
    }
    cout << endl;

    return 0;
}

