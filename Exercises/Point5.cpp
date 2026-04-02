#include <iostream>
#include <vector>

// ------------------------------------------------------
// Función: mergeSorted
// Recibe: dos vectores de enteros ordenados (a y b).
// Devuelve: un nuevo vector con todos los elementos de
//           a y b en orden ascendente.
// ------------------------------------------------------
std::vector<int> mergeSorted(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> result;                  // Vector resultado
    result.reserve(a.size() + b.size());      // Reservamos espacio suficiente

    size_t i = 0, j = 0;  // Índices para recorrer 'a' y 'b'

    // Recorremos ambos vectores mientras haya elementos en los dos
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            result.push_back(a[i]);
            i++;
        } else {
            result.push_back(b[j]);
            j++;
        }
    }

    // Si aún quedan elementos en 'a', los copiamos
    while (i < a.size()) {
        result.push_back(a[i]);
        i++;
    }

    // Si aún quedan elementos en 'b', los copiamos
    while (j < b.size()) {
        result.push_back(b[j]);
        j++;
    }

    return result;  // Retornamos el vector combinado
}

// ------------------------------------------------------
// Programa principal
// ------------------------------------------------------
int main() {
    // Dos vectores ya ordenados
    std::vector<int> v1 = {1, 3, 5, 7, 9};
    std::vector<int> v2 = {2, 4, 6, 8, 10, 12};

    // Llamamos a la función de merge
    std::vector<int> merged = mergeSorted(v1, v2);

    // Imprimimos el resultado
    std::cout << "Vector combinado: ";
    for (int elem : merged) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
