#include <iostream>
#include "bst.hh"
using namespace std;

void ArbolBinario::insertar(int k, int v) {
    // Si el árbol está vacío
    if (root == nullptr) {
        root = new node(k, v);
        size++;
        cout << "Nodo insertado: " << k << " - " << v << " (raíz)" << endl;
        return;
    }

    // Buscar posición adecuada
    node* actual = root;
    while (true) {
        if (k < actual->key) {
            if (actual->left == nullptr) {
                actual->left = new node(k, v);
                size++;
                cout << "Nodo insertado a la izquierda de " << actual->key << ": " << k << " - " << v << endl;
                break;
            } else {
                actual = actual->left;
            }
        } else if (k > actual->key) {
            if (actual->right == nullptr) {
                actual->right = new node(k, v);
                size++;
                cout << "Nodo insertado a la derecha de " << actual->key << ": " << k << " - " << v << endl;
                break;
            } else {
                actual = actual->right;
            }
        } else {
            actual->value = v;
            cout << "Nodo existente (" << k << ") actualizado con valor " << v << endl;
            break;
        }
    }

}

    node* ArbolBinario::buscar(int k) { //funcion para buscar un nodo
    node* actual = root;

    while (actual != nullptr) {
        if (k == actual->key) {
            cout << "Nodo encontrado: " << actual->key << " - " << actual->value << endl;
            return actual;
        } else if (k < actual->key) {
            actual = actual->left;
        } else {
            actual = actual->right;
        }
    }

    cout << "Nodo con clave " << k << " no encontrado." << endl;
    return nullptr;
}

