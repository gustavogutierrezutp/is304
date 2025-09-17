#include <iostream>

using namespace std;

/**
 * @brief A simple singly-linked list implementation.
 * 
 * @tparam T Type of elements stored in the list.
 */
template <typename T> class List {
private:
  /**
   * @brief Node class representing an element in the list.
   */
  class Node {
  private:
    T data;         ///< Value stored in the node.
    Node *next;     ///< Pointer to the next node.
  public:
    /**
     * @brief Default constructor. Initializes data and next pointer.
     */
    Node() : data(), next(nullptr) {}

    /**
     * @brief Constructor with value.
     * @param v Value to store in the node.
     */
    Node(const T& v) : data(v), next(nullptr) {}

    /**
     * @brief Get the next node pointer.
     * @return Pointer to the next node.
     */
    Node* getNext() const { return next; }

    /**
     * @brief Set the next node pointer.
     * @param n Pointer to the next node.
     */
    void setNext(Node *n) { next = n; }
  };

private:
  Node *first;      ///< Pointer to the first node in the list.
  Node *last;       ///< Pointer to the last node in the list.
  unsigned int sz;  ///< Number of elements in the list.

public:
  /**
   * @brief Default constructor. Initializes an empty list.
   */
  List() : first(nullptr), last(nullptr), sz(0) {}

  /**
   * @brief Destructor. Deletes all nodes in the list.
   */
  ~List() {
    Node *temp = first;
    while (first != nullptr) {
      temp = first;
      first = first->getNext();
      delete temp;
    }
    last = nullptr;
    sz = 0;
  }

  /**
   * @brief Check if the list is empty.
   * @return true if the list is empty, false otherwise.
   */
  bool empty() const { 
    return first == nullptr && last == nullptr;
  }

  /**
   * @brief Add an element to the end of the list.
   * @param val Value to add.
   */
  void push_back(const T &val) {
    Node *newNode = new Node(val);
    if (!empty()) {
      last->setNext(newNode);
      last = newNode;
    } else {
      first = newNode;
      last = newNode;
    }
    sz++;
  }

  void pop_back() {
    /** your implementation here */
  }
  void push_front( const T& val) {
    /** your implementation here */
  }
  void pop_front() {
    /** your implementation here */
  }
  T& front() {
    /** your implementation here */
  }
   const T& front() const {
    /** your implementation here */
  }
  T& back() {
    /** your implementation here */
  }
   const T& back() const {
    /** your implementation here */
  }
  unsigned int size() const {
    /** your implementation here */
  }
  void clear() {
    /** your implementation here */
  }
  const T& at(unsigned int index) const {
    /** your implementation here */
  }
  T& at(unsigned int index) {
    /** your implementation here */
  }
  const T& operator[](unsigned int index) const {
    /** your implementation here */
  }
  T& operator[](unsigned int index) {
    /** your implementation here */
  }
  void insert(unsigned int index, const T& val) {
    /** your implementation here */
  }
  void erase(unsigned int index) {
    /** your implementation here */
  }
  void print() const {
    Node *temp = first;
    while (temp != nullptr) {
      cout << temp->data << " ";
      temp = temp->getNext();
    }
    cout << endl; 
  }
  void reverse() {
    /** your implementation here */   
  }
  List(const List<T> &other) {
    /** your implementation here */
  }
  void push_back(const List<T> &other) {
    /** your implementation here */
  }
  void push_front(const List<T> &other) {
    /** your implementation here */
  }
};

/**
 * @brief Example usage of the List class.
 */
int main() {
  List<int> l;
  l.push_back(10);
  l.push_back(20);
  l.push_back(30);
  return 0;
}