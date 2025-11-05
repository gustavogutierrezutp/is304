#ifndef TREAP_HH
#define TREAP_HH

#include <iostream>
using namespace std;


struct Node {
    int key;        // Valor clave para el orden del BST
    int priority;   // Valor aleatorio que mantiene la propiedad del heap
    Node* left;     // Puntero al subárbol izquierdo
    Node* right;    // Puntero al subárbol derecho

    Node(int k);    // Constructor del nodo
};

class Treap {
private:
    Node* root;     // Raíz del Treap

    
    Node* insert(Node* root, int key);   // Inserción recursiva

public:
    Treap(); 
    void insert(int key);
    
};


#endif
