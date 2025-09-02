#include <iostream>
#include <vector>

// ------------------------------------------------------
// Programa: Dynamic Growth Test
// Objetivo: Insertar números del 1 al 1000 en un vector
//           y mostrar cada vez que cambia la capacidad.
// ------------------------------------------------------
int main() {
    std::vector<int> u;  // Vector vacío de enteros

    size_t old_capacity = u.capacity();  // Guardamos la capacidad inicial

    // Insertamos números del 1 al 1000
    for (int i = 1; i <= 1000; ++i) {
        u.push_back(i);

        // Si la capacidad cambia, imprimimos tamaño y capacidad
        if (u.capacity() != old_capacity) {
            old_capacity = u.capacity();
            std::cout << "Size: " << u.size()
                      << ", Capacity: " << u.capacity() << std::endl;
        }
    }

    return 0;
}
