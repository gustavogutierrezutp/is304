#include <iostream>
#include <cmath>
using namespace std;

class Vector {
    private:
        double * storage; //PUNTERO AL HEAP RESERVADO
        int size; //DIMENSIÓN DEL VECTOR
    public:
        // CONSTRUCTORES
        Vector (int s) { //INICIALIZA UN VECTOR DE DIMENSIÓN S EN CEROS
            size = s;
            storage = new double[s];
            for (int i = 0; i < s; i++) {
                storage[i] = 0;
            }
        }
        Vector (int s, const double init[]) { // INICIALIZA LOS VALORES DEL VECTOR CON UN ARRAY
            size = s;
            storage = new double[s];
            for (int i = 0; i < s; i++) {
                storage[i] = init[i];
            }
        }
        Vector (const Vector& other) {//CONSTRUCTOR DE COPIA
            size = other.size;
            storage = new double[other.size];
            for (int i = 0; i < other.size; i++) {
                storage[i] = other.storage[i];
            }
        }
        ~Vector () { //DESTRUCTOR
            delete[] storage; 
        }
        // ------------------------------------------ METODOS ------------------------------------------
        double SumaElementosVectores() {
            double resultado_suma = 0;
            for (int i = 0; i < size; i++) {
                resultado_suma += storage[i];
            }
            return resultado_suma;
        }
        void ImprimirVector() {
            for (int i = 0; i < size; i++) {
                std::cout << storage[i] << " ";
            }
            std::cout << std::endl;
        }
};
int main() {
    double vector_a[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    Vector A(5, vector_a);
    std::cout << "Vector A: ";
    A.ImprimirVector();
    double suma = A.SumaElementosVectores();
    std::cout << "Suma de los elementos del vector A: " << suma << std::endl;
    return 0;
}