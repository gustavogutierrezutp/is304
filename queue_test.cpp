#include "queue.hh"
#include "list.hh"
#include <iostream>

using namespace std;

void printElement(const int &e) {
  cout << "hola mundo " <<  e << endl;
}

int main() {
  List<int> lst;
  for (int i = 1; i <= 5; ++i) {
    lst.push_back(i);
  }
  //lst.apply(printElement);
  List<int> even;
  lst.apply(
    [&](const int &e) { 
     if (e % 2 == 0) {
       even.push_back(e); 
     }
    }
  );
  even.apply(printElement);
  lst.apply(printElement);
/*
  cout << "Queue Test" << endl;
  Queue<int> q;
  for (int i = 1; i <= 5; ++i) {
    q.push(i);
    cout << "Pushed: " << i << ", Queue size: " << q.size() << endl;
  }

  while (!q.empty()) {
    cout << "Front: " << q.front() << ", Queue size: " << q.size() << endl;
    q.pop();
  }
*/
  return 0; 
}