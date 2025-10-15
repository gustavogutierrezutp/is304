#ifndef __BST_HH__
#define __BST_HH__
#include <iostream>


class node { // estructura del nodo
private:
    int key;
    int value;
    node *left;
    node *right;

public:
    node(int k, int v) : key(k), value(v), left(nullptr), right(nullptr) {} // Constructor del nodo

    // Para que ArbolBinario pueda acceder a los atributos privados del nodo:
    friend class ArbolBinario;


};

class ArbolBinario {
private:
    node *root;
    unsigned int size;

    // 🔹 Función auxiliar para destruir los nodos recursivamente
    void destruir(node* nodo) {
        if (nodo != nullptr) {
            destruir(nodo->left);
            destruir(nodo->right);
            delete nodo;
        }
    }

public:
    ArbolBinario() : root(nullptr), size(0) {} // Constructor del árbol

    // 🔹 Destructor
    ~ArbolBinario() {
        destruir(root);   // libera todos los nodos
        root = nullptr;   // por seguridad
    }

    void insertar(int k, int v);

    node* buscar(int k);

    // Aquí luego puedes agregar más funciones:
    // void insertar(int k, int v);
    // void buscar(int k);
    // void eliminar(int k);
};

#endif // __BST_HH__
