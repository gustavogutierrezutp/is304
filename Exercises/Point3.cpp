#include <iostream>
#include <vector>

// ------------------------------------------------------
// Función: filterEven
// Recibe: un vector constante de enteros (std::vector<int>&)
// Devuelve: un nuevo vector que contiene únicamente los números pares
// ------------------------------------------------------
std::vector<int> filterEven(const std::vector<int>& v) {
    std::vector<int> pares;  // Vector donde guardaremos los números pares

    // Recorremos todos los elementos del vector original
    for (int elem : v) {
        if (elem % 2 == 0) {        // Verificamos si es par
            pares.push_back(elem);  // Si lo es, lo añadimos al nuevo vector
        }
    }

    return pares; // Devolvemos el vector resultante
}

// ------------------------------------------------------
// Función principal
// ------------------------------------------------------
int main() {
    // Creamos un vector con valores de prueba
    std::vector<int> datos = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Filtramos solo los pares
    std::vector<int> pares = filterEven(datos);

    // Mostramos el resultado
    std::cout << "Números pares: ";
    for (int elem : pares) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
