#include "treap.hh"
#include <cstdlib>
// ---------------------------
// CONSTRUCTOR DEL NODO
// ---------------------------
Node::Node(int k) {
    key = k;
    priority = rand() % 100; // Prioridad aleatoria entre 0 y 99
    left = right = nullptr;
}

// ---------------------------
// CONSTRUCTOR DE LA CLASE TREAP
// ---------------------------
Treap::Treap() {
    root = nullptr;
}

void Treap::insert(int key) {
    root = insert(root, key);  // llama a la versión recursiva privada
}





