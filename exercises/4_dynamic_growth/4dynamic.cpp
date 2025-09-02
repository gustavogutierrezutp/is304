#include <iostream>
#include "vector.t"
using namespace std;

Vector<int> mergeSorted(const Vector<int>& a, const Vector<int>& b) {
    Vector<int> result;
    int i = 0;
    int j = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            result.push_back(a[i]);
            i++;
        } else {
            result.push_back(b[j]);
            j++;
        }
    }

    while (i < a.size()) {
        result.push_back(a[i]);
        i++;
    }

    while (j < b.size()) {
        result.push_back(b[j]);
        j++;
    }

    return result;
}

int main() {
    Vector<int> first;
    first.push_back(1);
    first.push_back(3);
    first.push_back(5);

    Vector<int> second;
    second.push_back(2);
    second.push_back(4);
    second.push_back(6);

    Vector<int> merged = mergeSorted(first, second);

    for (int i = 0; i < merged.size(); i++) {
        cout << merged[i] << " ";
    }

    cout << endl;
    return 0;
}
