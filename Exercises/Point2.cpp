#include <iostream>   // Librería para entrada y salida estándar (cout, cin, etc.)
#include <vector>     // Librería que permite usar el contenedor dinámico std::vector

// ------------------------------------------------------
// Función: reverseVector
// Recibe: un vector constante de enteros (std::vector<int>&)
// Devuelve: un nuevo vector con los elementos en orden inverso
// ------------------------------------------------------
std::vector<int> reverseVector(const std::vector<int>& v) {
    std::vector<int> reversed;        // Vector que almacenará el resultado
    reversed.reserve(v.size());       // Reservamos memoria del mismo tamaño que 'v'
                                      // Esto mejora la eficiencia al evitar realocaciones

    // Recorremos el vector original desde el último elemento hasta el primero
    for (int i = static_cast<int>(v.size()) - 1; i >= 0; --i) {
        reversed.push_back(v[i]);     // Insertamos cada elemento al final del nuevo vector
    }

    return reversed;  // Retornamos el vector invertido
}

// ------------------------------------------------------
// Función principal (punto de entrada del programa)
// ------------------------------------------------------
int main() {
    // Declaramos e inicializamos un vector de enteros
    std::vector<int> datos = {1, 2, 3, 4, 5};

    // Obtenemos un nuevo vector con los elementos invertidos
    std::vector<int> invertido = reverseVector(datos);

    // Mostramos el vector invertido en la salida estándar
    std::cout << "Vector invertido: ";
    for (int elem : invertido) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Fin del programa
    return 0;
}
