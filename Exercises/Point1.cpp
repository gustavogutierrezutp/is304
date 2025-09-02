#include <iostream>  // Librería para entrada/salida (cout, cin, etc.)
#include <vector>    // Librería que permite usar std::vector

// ------------------------------------------------------
// Función: sumVector
// Recibe: un vector constante de enteros (std::vector<int>&)
// Devuelve: la suma de todos los elementos del vector
// ------------------------------------------------------
int sumVector(const std::vector<int>& v) {
    int suma = 0;  // Variable acumuladora
    // Recorremos todos los elementos del vector
    for (int elem : v) {
        suma += elem;  // Sumamos cada elemento a 'suma'
    }
    return suma;  // Retornamos el resultado total
}

// ------------------------------------------------------
// Función principal (punto de entrada del programa)
// ------------------------------------------------------
int main() {
    // Creamos un vector de enteros con valores iniciales
    std::vector<int> datos = {10, 20, 30, 40, 50};

    // Imprimimos en pantalla la suma de los elementos del vector
    std::cout << "La suma es: " << sumVector(datos) << std::endl;

    // Terminamos el programa
    return 0;
}

