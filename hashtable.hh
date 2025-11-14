#ifndef __HASHTABLE_HH__
#define __HASHTABLE_HH__

#include <vector>
#include <list>
#include <utility>
#include <string>
#include <iostream>

using namespace std;

class Hashtable {
private:
  unsigned int m;
  vector<list<pair<string, string>>> storage;
  unsigned int sz;
  unsigned int hash(const string &key) const {
    return key.length(); // Simple hash function based on string length
    //return std::hash<std::string>{}(key); // Better hash function using std::hash
  }
public:
  Hashtable(unsigned int vector_size) : m(vector_size), storage(m, list<pair<string, string>>()), sz(0) {}
  ~Hashtable() {}
  void insert(const string &key, const string &value) {
    unsigned int index = hash(key) % m;
    cout << "Inserting key: " << key << " at index: " << index << endl;
    for (auto it = storage[index].begin(); it != storage[index].end(); ++it) {
      if (it->first == key) {
        cout << "Updating key: " << key << " at index: " << index << endl;
        it->second = value;
        return;
      }
    }
    pair<string, string> entry = make_pair(key, value);
    storage[index].push_back(entry);
    sz++;
  }

  unsigned int size() const {
    return sz;
  }

  void debug() {
    for (unsigned int i = 0; i < m; ++i) {
      cout << "Index " << i << ": ";
      for (const auto &entry : storage[i]) {
        cout << "{" << entry.first << ": " << entry.second << "} ";
      }
      cout << endl;
    }
  }
};

#endif // __HASHTABLE_HH__