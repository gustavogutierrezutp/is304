#include <iostream>
#include <cmath>
using namespace std;    

//VECTOR EN ALGEBRA LINEAL, INCLUYE OPERACIONES COMO SUMA, RESTA, MULTIPLICACION POR ESCALAR, PRODUCTO PUNTO, MAGNITUD, ETC.
template <typename V> class AlgebraVector {
    private:
        V *storage; //Puntero al heap
        int size; //Dimensión del vector
    public:
        // ------------------------------------------ CONSTRUCTORES ------------------------------------------
        AlgebraVector(int s) { //INICIALIZA UN VECTOR DE DIMENSIÓN s, este solo es para crear un vector de ceros sin copiar datos de un array
            size = s;
            storage = new V[s]; //Reserva memoria en el heap
            for (int i = 0; i < s; i++) {
                storage[i] = 0; //Inicializa en 0
            }
        }
        AlgebraVector (int s, const V init[]) {
            size = s;
            storage = new V[s];
            for (int i = 0; i < s; i++) {
                storage[i] = init[i];
            }
        }
        AlgebraVector (const AlgebraVector& other) { //CONSTRUCTOR DE COPIA
            size = other.size;
            storage = new V[other.size];
            for (int i = 0; i < other.size; i++) {
                storage[i] = other.storage[i];
            }
        }
        ~AlgebraVector() { //DESTRUCTOR
            delete[] storage; //Libera memoria en el heap
        }
        // ------------------------------------------ METODOS ------------------------------------------
        AlgebraVector<V> SumaVectores (const AlgebraVector& other) {
            if (size != other.size) {
                std::cout <<"Error: Los vectores deben tener la misma dimensión para sumar.\n";
                return AlgebraVector<V>(0);
            } else {
                AlgebraVector<V> ResultadoSuma(size);
                for (int i = 0; i < size; i++) {
                    ResultadoSuma.storage[i] = storage[i] + other.storage[i];
                }
                return ResultadoSuma;
            }
        };
        AlgebraVector<V> RestaVectores (const AlgebraVector& other) {
            if (size != other.size) {
                std::cout <<"Error: Los vectores deben tener la misma dimensión para restar.\n";
                return AlgebraVector<V>(0);
            } else {
                AlgebraVector<V> ResultadoResta(size);
                for (int i = 0; i < size; i++) {
                    ResultadoResta.storage[i] = storage[i] - other.storage[i];
                }
                return ResultadoResta;
            }
        }
        AlgebraVector<V> MultiplicacionEscalar (double escalar) const {
            AlgebraVector<V> ResultadoMultiplicacion(size);
            for (int i = 0; i < size; i++) {
                ResultadoMultiplicacion.storage[i] = storage[i] * escalar;
            }
            return ResultadoMultiplicacion;
        };
        V ProductoPunto (const AlgebraVector& other) const {
            if (size != other.size){
                std:: cout <<"Error: Los vectores deben tener la misma dimensión para el producto punto.\n";
                return 0;
            } else {    
                V resultado = 0;
                for (int i = 0; i < size; i++) {
                    resultado += storage[i] * other.storage[i];
                }
                return resultado;
            }
        };
        V Magnitud () const {
            V discriminante = 0;
            for (int i = 0; i< size; i++) {
                discriminante += storage[i] * storage[i];
            }
            return sqrt(discriminante);
        };
        AlgebraVector<V> ImprimirVector() {
            for (int i = 0; i < size; i++) {
                std::cout << storage[i] << " ";
            }
            return *this;
        };
};

int main() {
    double a_init[] = {1.0, 2.0, 3.0}; //ESTOS DOS VECTORES SON ORTOGONALES, ASÍ QUE EL PRODUCTO PUNTO TIENE QUE DAR CERO 
    double b_init[] = {3.0, -6.0, 3.0};

    AlgebraVector<double> a(3, a_init);
    AlgebraVector<double> b(3, b_init);

    std::cout << "Vector A: ";
    a.ImprimirVector();
    std::cout << "\nVector B: ";
    b.ImprimirVector();
    std::cout << "\n";

    std::cout << "Suma de A y de B: ";
    AlgebraVector<double> suma = a.SumaVectores(b);
    suma.ImprimirVector();
    std::cout << "\n";

    std::cout <<"Resta de A y de B: ";
    AlgebraVector<double> resta = a.RestaVectores(b);
    resta.ImprimirVector();
    std::cout << "\n";

    std::cout <<"Multiplicacion de A por el escalar 10: ";
    AlgebraVector<double> multiplicacion = a.MultiplicacionEscalar(10);
    multiplicacion.ImprimirVector();
    std::cout << "\n";

    std::cout <<"Producto punto de A y B: ";
    double producto = a.ProductoPunto(b);
    std::cout << producto << "\n";

    std::cout <<"Magnitud de A: ";
    double magnitud = a.Magnitud();
    std::cout << magnitud << "\n";

    return 0;
}