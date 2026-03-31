#include <iostream>
#include <vector>
using namespace std;

vector<int> u;   // Vector global

// 🔹 Función para agregar un elemento
void agregarElemento(vector<int>& v) {
    int valor;
    cout << "Ingrese un elemento: ";
    cin >> valor;
    v.push_back(valor);

    cout << "Tamaño actual: " << v.size() << endl;
    cout << "Capacidad actual: " << v.capacity() << endl;
}

int main() {
    int opcion;

    while (true) {   // 🔹 Bucle infinito hasta que el usuario decida salir
        cout << "1. Agregar un elemento al vector" << endl;
        cout << "2. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarElemento(u);
                break;

            case 2:
                return 0;  // 🔹 Salimos del programa

            default:
                cout << "Opcion invalida, intente de nuevo." << endl;
        }
    }

    return 0;
}
