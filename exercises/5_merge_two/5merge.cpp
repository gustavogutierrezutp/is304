#include <iostream>
#include <vector>
using namespace std;


vector<int> mergeSorted(const vector<int>& a, const vector<int>& b) {
    vector<int> result; 
    int i = 0; 
    int j = 0; 

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
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
    vector<int> vec1 = {1, 3, 5, 7};
    vector<int> vec2 = {2, 4, 6, 8, 10};

    vector<int> merged = mergeSorted(vec1, vec2);

    cout << "Vector combinado y ordenado: ";
    for (int num : merged) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
