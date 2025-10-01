#ifndef __BST_HH__
#define __BST_HH__

/**
 * Key: Type of the key
 * Value: Type of the value
 */
template <typename Key, typename Value> class BST {
private:
  class Node {
  private:
    Key key;
    Value value;
    Node *left;
    Node *right;

  public:
    Node(const Key &k, const Value &v)
        : key(k), value(v), left(nullptr), right(nullptr) {}
    const Key &getKey() const { return key; }
    bool hasLeft() const { return left != nullptr; }
    bool hasRight() const { return right != nullptr; }
    Node *getLeft() const { return left; }
    Node *getRight() const { return right; }
    void setLeft(Node *n) { left = n; }
    void setRight(Node *n) { right = n; }
    void setValue(const Value &v) { value = v; }
  };

private:
  Node *root;
  unsigned int sz;

public:
  BST() : root(nullptr), sz(0) {}

  unsigned int size() const { return sz; }
  bool empty() const { return root == nullptr; }

  void insert(const Key &k, const Value &v) {
    if (empty()) {
      root = new Node(k, v);
      sz++;
      return;
    } else {
      insert(root, k, v);
    }
  }

private:
  void insert(Node *node, const Key &k, const Value &v) {
    if (k < node->getKey()) {
      if (node->hasLeft()) {
        insert(node->getLeft(), k, v);
      } else {
        Node *newNode = new Node(k, v);
        node->setLeft(newNode);
        sz++;
      }
    } else if (node->getKey() < k) {
      if (node->hasRight()) {
        insert(node->getRight(), k, v);
      } else {
        Node *newNode = new Node(k, v);
        node->setRight(newNode);
        sz++;
      }
    } else {
      // k already exists in the tree, update value
      node->setValue(v);
    }
  }

public:
  bool find(const Key &k) const {
    if (empty()) {
      return false;
    }
    return find(root, k);
  }

private:
  bool find(Node *node, const Key &k) const {
    if (node == nullptr)
      return false;
    else if (k < node->getKey())
      return find(node->getLeft(), k);
    else if (node->getKey() < k)
      return find(node->getRight(), k);
    else
      return true;
  }
};
#endif