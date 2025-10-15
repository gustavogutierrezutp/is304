#include <iostream>
#include "bst.hh" // 👈 incluimos el archivo de encabezado
using namespace std;

int main() {
    ArbolBinario arbol;
    arbol.insertar(10, 100);
    arbol.insertar(20, 200);

     cout << endl;

    arbol.buscar(20);  // ✅ Debería encontrarlo
    arbol.buscar(7);   // ❌ No existe

    return 0;
} 