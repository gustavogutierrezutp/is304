#ifndef __QUEUE_HH__
#define __QUEUE_HH__
#include "list.hh"

template <typename T> class Queue {
private:
  List<T> storage; ///< Internal list to store queue elements
public:
  Queue() : storage() {}
  /* Queue(const Queue<T> &other) : storage(other.storage) {}  */
  ~Queue() {}
  void push(const T &e) { storage.push_back(e); }
  unsigned int size() const { return storage.size(); }
  bool empty() const { return storage.empty(); }
  T &front() { return storage.front(); }
  const T &front() const { return storage.front(); }
  void pop() { storage.pop_front(); }
};
#endif // __QUEUE_HH__