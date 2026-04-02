#include <iostream>
#include <cmath>
#include <stdexcept>

// ------------------------------------------------------
// Clase: LAVector
// Representa un vector matemático en el contexto del
// álgebra lineal, NO un contenedor de datos como std::vector.
// ------------------------------------------------------
class LAVector {
private:
    int dim;          // Dimensión del vector (ej. 2D, 3D, nD)
    double* data;     // Arreglo dinámico que guarda los componentes

public:
    // -------- Constructor normal --------
    // Crea un vector de dimensión 'dimension' con valores iniciales.
    LAVector(int dimension, double init_value = 0.0) : dim(dimension) {
        if (dim <= 0) throw std::invalid_argument("La dimensión debe ser positiva.");
        data = new double[dim];
        for (int i = 0; i < dim; ++i) {
            data[i] = init_value; // Inicializamos con el valor dado
        }
    }

    // -------- Constructor con lista de inicialización --------
    // Ejemplo: LAVector v = {1.0, 2.0, 3.0};
    LAVector(std::initializer_list<double> values) : dim(values.size()) {
        data = new double[dim];
        int i = 0;
        for (double val : values) {
            data[i++] = val;
        }
    }

    // -------- Constructor de copia --------
    // Se usa cuando creamos un nuevo vector a partir de otro existente.
    LAVector(const LAVector& other) : dim(other.dim) {
        data = new double[dim];
        for (int i = 0; i < dim; ++i) {
            data[i] = other.data[i];
        }
    }

    // -------- Destructor --------
    // Libera la memoria dinámica usada por el arreglo data.
    ~LAVector() {
        delete[] data;
    }

    // -------- Operador de asignación (=) --------
    // Permite hacer: v1 = v2;
    LAVector& operator=(const LAVector& other) {
        if (this == &other) return *this; // Evita auto-asignación
        delete[] data;

        dim = other.dim;
        data = new double[dim];
        for (int i = 0; i < dim; ++i) {
            data[i] = other.data[i];
        }
        return *this;
    }

    // -------- Operador + (suma de vectores) --------
    LAVector operator+(const LAVector& rhs) const {
        if (dim != rhs.dim) throw std::invalid_argument("Dimensiones incompatibles para la suma.");
        LAVector result(dim);
        for (int i = 0; i < dim; ++i) {
            result.data[i] = data[i] + rhs.data[i];
        }
        return result;
    }

    // -------- Operador - (resta de vectores) --------
    LAVector operator-(const LAVector& rhs) const {
        if (dim != rhs.dim) throw std::invalid_argument("Dimensiones incompatibles para la resta.");
        LAVector result(dim);
        for (int i = 0; i < dim; ++i) {
            result.data[i] = data[i] - rhs.data[i];
        }
        return result;
    }

    // -------- Operador * (multiplicación por escalar) --------
    // Ejemplo: v * 2.0 → multiplica cada componente por 2.
    LAVector operator*(double scalar) const {
        LAVector result(dim);
        for (int i = 0; i < dim; ++i) {
            result.data[i] = data[i] * scalar;
        }
        return result;
    }

    // -------- Producto punto (dot product) --------
    // v1 · v2 = x1*x2 + y1*y2 + z1*z2 ...
    double dot_product(const LAVector& rhs) const {
        if (dim != rhs.dim) throw std::invalid_argument("Dimensiones incompatibles para producto punto.");
        double result = 0.0;
        for (int i = 0; i < dim; ++i) {
            result += data[i] * rhs.data[i];
        }
        return result;
    }

    // -------- Magnitud (norma Euclídea) --------
    // ||v|| = sqrt(x^2 + y^2 + z^2 ...)
    double magnitude() const {
        double sum = 0.0;
        for (int i = 0; i < dim; ++i) {
            sum += data[i] * data[i];
        }
        return std::sqrt(sum);
    }

    // -------- Normalización --------
    // Convierte el vector en unitario (magnitud = 1).
    LAVector normalize() const {
        double mag = magnitude();
        if (mag == 0) throw std::runtime_error("No se puede normalizar un vector nulo.");
        return (*this) * (1.0 / mag);
    }

    // -------- Método de utilidad: imprimir --------
    void print() const {
        std::cout << "(";
        for (int i = 0; i < dim; ++i) {
            std::cout << data[i];
            if (i < dim - 1) std::cout << ", ";
        }
        std::cout << ")";
    }
};

// ------------------------------------------------------
// Programa de prueba
// ------------------------------------------------------
int main() {
    // Creamos dos vectores en R^3 (3D)
    LAVector v1 = {1.0, 2.0, 3.0};
    LAVector v2 = {4.0, 5.0, 6.0};

    // Suma
    LAVector suma = v1 + v2;
    std::cout << "Suma: "; suma.print(); std::cout << std::endl;

    // Resta
    LAVector resta = v1 - v2;
    std::cout << "Resta: "; resta.print(); std::cout << std::endl;

    // Multiplicación por escalar
    LAVector escalar = v1 * 2.0;
    std::cout << "Escalar (v1 * 2): "; escalar.print(); std::cout << std::endl;

    // Producto punto
    double dot = v1.dot_product(v2);
    std::cout << "Producto punto (v1 · v2): " << dot << std::endl;

    // Magnitud
    std::cout << "Magnitud de v1: " << v1.magnitude() << std::endl;

    // Normalización
    LAVector v1_norm = v1.normalize();
    std::cout << "Normalización de v1: "; v1_norm.print(); std::cout << std::endl;

    return 0;
}
