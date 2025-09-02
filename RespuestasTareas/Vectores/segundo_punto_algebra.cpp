#include <iostream>
#include <cmath>
using namespace std;

// ---------------------------------------------------------
// (1) Clase plantilla AlgebraVector
// ---------------------------------------------------------

template <typename V>
class AlgebraVector {
private:
    V *storage;
    int size;

public:
    // ------------------------------------------ CONSTRUCTORES ------------------------------------------
    AlgebraVector(int s) { //INICIALIZA UN VECTOR DE DIMENSIÓN 0 RELLENANDO TODOS SUS VALORES CON CERO
        size = s;
        storage = new V[s];
        for (int i = 0; i < size; i++) {
            storage[i] = 0;
        }
    }

    AlgebraVector(int s, const V init[]) {
        size = s;
        storage = new V[s];
        for (int i = 0; i < size; i++) {
            storage[i] = init[i];
        }
    }

    AlgebraVector(const AlgebraVector& other) { //CONSTRUCTOR DE COPIA
        size = other.size;
        storage = new V[size];
        for (int i = 0; i < size; i++) {
            storage[i] = other.storage[i];
        }
    }

    // ------------------------------------------ DESTRUCTOR ------------------------------------------
    ~AlgebraVector() {
        delete[] storage;
    }

    // ------------------------------------------ COPY ASSIGNMENT OPERATOR ------------------------------------------
    AlgebraVector& operator=(const AlgebraVector& other) {
        if (this != &other) {
            delete[] storage;
            size = other.size;
            storage = new V[size];
            for (int i = 0; i < size; i++) {
                storage[i] = other.storage[i];
            }
        }
        return *this;
    }

    // ------------------------------------------ OPERADORES ------------------------------------------
    V& operator[](int index) { //PERMITE ACCEDER A LOS ELEMENTOS INTERNOS DE UNA INSTANCIA DE CLASE, ESTA VERSIÓN PERMITE MODIFICAR LOS OBJETOS
        return storage[index];
    }

    const V& operator[](int index) const {  //VERSIÓN PARA OBJETOS CONSTANTES, NO PERMITE MODIFICAR EL OBJETO, SOLO LEERLO
        return storage[index];
    }

    // ------------------------------------------ MÉTODOS ------------------------------------------
    AlgebraVector<V> SumaVectores(const AlgebraVector& other) const {
        if (size != other.size) {
            cout << "Error: los vectores deben tener la misma dimensión para sumar.\n";
            return AlgebraVector<V>(0);
        }
        AlgebraVector<V> resultado(size);
        for (int i = 0; i < size; i++) {
            resultado.storage[i] = storage[i] + other.storage[i];
        }
        return resultado;
    }

    AlgebraVector<V> RestaVectores(const AlgebraVector& other) const {
        if (size != other.size) {
            cout << "Error: los vectores deben tener la misma dimensión para restar.\n";
            return AlgebraVector<V>(0);
        }
        AlgebraVector<V> resultado(size);
        for (int i = 0; i < size; i++) {
            resultado.storage[i] = storage[i] - other.storage[i];
        }
        return resultado;
    }

    AlgebraVector<V> MultiplicacionEscalar(double escalar) const {
        AlgebraVector<V> resultado(size);
        for (int i = 0; i < size; i++) {
            resultado.storage[i] = storage[i] * escalar;
        }
        return resultado;
    }

    V ProductoPunto(const AlgebraVector& other) const {
        if (size != other.size) {
            cout << "Error: los vectores deben tener la misma dimensión para el producto punto.\n";
            return V(0);
        }
        V sum = 0;
        for (int i = 0; i < size; i++) {
            sum += storage[i] * other.storage[i];
        }
        return sum;
    }

    V Magnitud() const {
        V sum = 0;
        for (int i = 0; i < size; i++) {
            sum += storage[i] * storage[i];
        }
        return sqrt(sum);
    }

    void ImprimirVector() const {
        for (int i = 0; i < size; i++) {
            cout << storage[i] << " ";
        }
    }
};

// ---------------------------------------------------------
// (2) Clase MatrizAlgebra
// ---------------------------------------------------------

class MatrizAlgebra {
private:
    int filas, columnas;
    AlgebraVector<double>** storage;

public:
    // ------------------------------------------ CONSTRUCTORES ------------------------------------------
    MatrizAlgebra(int f, int c) : filas(f), columnas(c) {
        storage = new AlgebraVector<double>*[filas];
        for (int i = 0; i < filas; ++i) {
            storage[i] = new AlgebraVector<double>(columnas);
        }
    }

    MatrizAlgebra(int f, int c, const double init[])
        : filas(f), columnas(c) {
        storage = new AlgebraVector<double>*[filas];
        for (int i = 0; i < filas; ++i) {
            storage[i] = new AlgebraVector<double>(columnas, &init[i * columnas]);
        }
    }

    MatrizAlgebra(const MatrizAlgebra& other)
        : filas(other.filas), columnas(other.columnas) {
        storage = new AlgebraVector<double>*[filas];
        for (int i = 0; i < filas; ++i) {
            storage[i] = new AlgebraVector<double>(*(other.storage[i]));
        }
    }

    // ------------------------------------------ DESTRUCTOR ------------------------------------------
    ~MatrizAlgebra() {
        for (int i = 0; i < filas; ++i) {
            delete storage[i];
        }
        delete[] storage;
    }

    // ------------------------------------------ MÉTODOS ------------------------------------------
    MatrizAlgebra SumaMatrices(const MatrizAlgebra& other) const {
        if (filas != other.filas || columnas != other.columnas) {
            cout << "Error: las matrices deben tener las mismas dimensiones para sumar.\n";
            return MatrizAlgebra(0, 0);
        }
        MatrizAlgebra resultado(filas, columnas);
        for (int i = 0; i < filas; ++i) {
            *resultado.storage[i] =
                storage[i]->SumaVectores(*other.storage[i]);
        }
        return resultado;
    }

    MatrizAlgebra MultiplicacionEscalar(double escalar) const {
        MatrizAlgebra resultado(filas, columnas);
        for (int i = 0; i < filas; ++i) {
            *resultado.storage[i] =
                storage[i]->MultiplicacionEscalar(escalar);
        }
        return resultado;
    }

    MatrizAlgebra Transpuesta() const {
        MatrizAlgebra resultado(columnas, filas);
        for (int i = 0; i < columnas; ++i) {
            for (int j = 0; j < filas; ++j) {
                (*resultado.storage[i])[j] = (*storage[j])[i];
            }
        }
        return resultado;
    }

    MatrizAlgebra VectorMatriz(const MatrizAlgebra& vec) const {
        if (columnas != vec.filas) {
            cout << "Error: columnas de A deben igual filas de X.\n";
            return MatrizAlgebra(0, 0);
        }
        MatrizAlgebra resultado(filas, vec.columnas);
        for (int i = 0; i < filas; ++i) {
            double sum = 0;
            for (int j = 0; j < columnas; ++j) {
                sum += (*storage[i])[j] * (*vec.storage[j])[0];
            }
            (*resultado.storage[i])[0] = sum;
        }
        return resultado;
    }

    void ImprimirMatriz() const {
        for (int i = 0; i < filas; ++i) {
            storage[i]->ImprimirVector();
            cout << endl;
        }
    }
};

int main() {
    double matrizA[] = {
        1, 3, 0,
        2, 4, 1,
        0, 5, 6
    };
    double matrizB[] = {
        2, 3, 4,
        9, 8, 7,
        6, 5, 4
    };
    double vectorX[] = {
        1,
        0,
        3
    };

    MatrizAlgebra A(3, 3, matrizA);
    MatrizAlgebra B(3, 3, matrizB);
    MatrizAlgebra X(3, 1, vectorX);

    cout << "Matriz A:\n";
    A.ImprimirMatriz();

    cout << "Matriz B:\n";
    B.ImprimirMatriz();

    cout << "Vector X:\n";
    X.ImprimirMatriz();

    cout << "Suma de A y B:\n";
    MatrizAlgebra C = A.SumaMatrices(B);
    C.ImprimirMatriz();

    cout << "Multiplicación de A por el escalar 2:\n";
    MatrizAlgebra D = A.MultiplicacionEscalar(2);
    D.ImprimirMatriz();

    cout << "Transpuesta de A:\n";
    MatrizAlgebra E = A.Transpuesta();
    E.ImprimirMatriz();

    cout << "Producto de A por el vector X:\n";
    MatrizAlgebra F = A.VectorMatriz(X);
    F.ImprimirMatriz();

    return 0;
}
