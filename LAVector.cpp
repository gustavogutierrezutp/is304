/*
Names: Juan Jose Posada Arboleda and Juan Jose Mendez Lozano
Teacher: Gustavo Adolfo Gutierrez
Course: Data Structures 2025-2
Date: 09/01/2025
Description: 
   
*/
#include <iostream>
#include <cmath>
using namespace std;

//Ejercicio 6: Operaciones con vectores (suma, resta, multiplicacion escalar, producto escalar, magnitud, normalizacion)
class LAVector {
private:
    int n;        // dimensión del vector
    double* data; // arreglo dinámico

public:
    LAVector() {
        n = 0;
        data = nullptr;
    }
    LAVector(int dim, double val = 0.0) {
        n = dim;
        data = new double[n];
        for (int i = 0; i < n; i++)
            data[i] = val;
    }
    // Constructor de copia
    LAVector(const LAVector& other) {
        n = other.n;
        data = new double[n];
        for (int i = 0; i < n; i++)
            data[i] = other.data[i];
    }
    ~LAVector() {
        delete[] data;
    }
    // Asignación
    LAVector& operator=(const LAVector& other) {
        if (this != &other) {
            delete[] data;
            n = other.n;
            data = new double[n];
            for (int i = 0; i < n; i++)
                data[i] = other.data[i];
        }
        return *this;
    }
    // Acceso a elementos
    double& operator[](int i) { return data[i]; }
    const double& operator[](int i) const { return data[i]; }

    int size() const { return n; }

    // Suma
    LAVector operator+(const LAVector& other) const {
        LAVector result(n);
        for (int i = 0; i < n; i++)
            result[i] = data[i] + other[i];
        return result;
    }
    // Resta
    LAVector operator-(const LAVector& other) const {
        LAVector result(n);
        for (int i = 0; i < n; i++)
            result[i] = data[i] - other[i];
        return result;
    }
    // Multiplicación escalar
    LAVector operator*(double scalar) const {
        LAVector result(n);
        for (int i = 0; i < n; i++)
            result[i] = data[i] * scalar;
        return result;
    }
    // Producto escalar
    double dot_product(const LAVector& other) const {
        double sum = 0.0;
        for (int i = 0; i < n; i++)
            sum += data[i] * other[i];
        return sum;
    }
    // Magnitud
    double magnitude() const {
        return sqrt(dot_product(*this));
    }
    // Normalización
    LAVector normalize() const {
        double mag = magnitude();
        if (mag == 0) {
            cout << "No se puede normalizar un vector nulo." << endl;
            return *this;
        }
        return (*this) * (1.0 / mag);
    }
    // Mostrar vector
    void print() const {
        cout << "(";
        for (int i = 0; i < n; i++) {
            cout << data[i];
            if (i < n - 1) cout << ", ";
        }
        cout << ")";
    }
};

// Ejercicio 7: Matriz por vector, suma de matrices, multiplicación escalar, transpuesta.
class Matrix {
private:
    int rows, cols;
    LAVector* data; // cada fila es un LAVector

public:
    Matrix(int r, int c, double val = 0.0) {
        rows = r; cols = c;
        data = new LAVector[rows];
        for (int i = 0; i < rows; i++)
            data[i] = LAVector(cols, val);
    }
    Matrix(const Matrix& other) {
        rows = other.rows;
        cols = other.cols;
        data = new LAVector[rows];
        for (int i = 0; i < rows; i++)
            data[i] = other.data[i];
    }

    ~Matrix() { delete[] data; }

    LAVector& operator[](int i) { return data[i]; }
    const LAVector& operator[](int i) const { return data[i]; }

    int rowCount() const { return rows; }
    int colCount() const { return cols; }

    // Multiplicación matriz-vector
    LAVector operator*(const LAVector& v) const {
        LAVector result(rows);
        for (int i = 0; i < rows; i++)
            result[i] = data[i].dot_product(v);
        return result;
    }
    // Suma de matrices
    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result[i][j] = data[i][j] + other[i][j];
        return result;
    }
    // Multiplicación escalar
    Matrix operator*(double scalar) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result[i][j] = data[i][j] * scalar;
        return result;
    }
    // Transpuesta
    Matrix transpose() const {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result[j][i] = data[i][j];
        return result;
    }
    // Mostrar matriz
    void print() const {
        for (int i = 0; i < rows; i++) {
            data[i].print();
            cout << endl;
        }
    }
};

// Ejercicio 8: Capa de red neuronal (pesos, sesgos, función de activación sigmoide y ReLU)
class NeuralLayer {
private:
    Matrix weights;  // Matriz de pesos (salidas x entradas)
    LAVector bias;   // Vector de sesgo (una entrada por salida)
    bool useReLU;    // Activación: false = sigmoide, true = ReLU

    // Función sigmoide
    double sigmoid(double x) const {
        return 1.0 / (1.0 + exp(-x));
    }

    // ReLU
    double relu(double x) const {
        return (x > 0) ? x : 0;
    }

public:
    NeuralLayer(int inputSize, int outputSize, bool relu = false)
        : weights(outputSize, inputSize), bias(outputSize, 0.0), useReLU(relu) {}

    // Configurar pesos y sesgos manualmente (para pruebas)
    void setWeight(int i, int j, double val) { weights[i][j] = val; }
    void setBias(int i, double val) { bias[i] = val; }

    // Propagación hacia adelante
    LAVector forward(const LAVector& input) const {
        // Wx + b
        LAVector z = (weights * input);
        for (int i = 0; i < z.size(); i++)
            z[i] += bias[i];

        // Activación
        LAVector output(z.size());
        for (int i = 0; i < z.size(); i++) {
            output[i] = useReLU ? relu(z[i]) : sigmoid(z[i]);
        }
        return output;
    }
};

/*
A continuacion se presentan los main para probar con cada uno de los ejercicios propuestos, 
cada uno esta comentado para evitar conflictos al momento de compilar y ejecutar el programa, entonces 
quitar los comentarios para poder probar cada uno.
*/

/*
// Main de prueba ejercicio 6 con valores predeterminados
int main() {
    LAVector v1(3); // vector de dimensión 3
    v1[0] = 3; v1[1] = 4; v1[2] = 0;

    LAVector v2(3);
    v2[0] = 1; v2[1] = 2; v2[2] = 3;

    cout << "v1 = "; v1.print(); cout << endl;
    cout << "v2 = "; v2.print(); cout << endl;

    LAVector suma = v1 + v2;
    cout << "v1 + v2 = "; suma.print(); cout << endl;

    LAVector resta = v1 - v2;
    cout << "v1 - v2 = "; resta.print(); cout << endl;

    LAVector escalar = v1 * 2.5;
    cout << "v1 * 2.5 = "; escalar.print(); cout << endl;

    cout << "Producto escalar v1·v2 = " << v1.dot_product(v2) << endl;
    cout << "Magnitud de v1 = " << v1.magnitude() << endl;

    LAVector norm = v1.normalize();
    cout << "Normalizado v1 = "; norm.print(); cout << endl;

    return 0;
}
*/

/*
// Main de prueba ejercicio 7 con valores predeterminados 
int main() {
    // Matriz de rotación 2D (45 grados)
    double angle = M_PI / 4; // 45 grados en radianes
    Matrix R(2, 2);
    R[0][0] = cos(angle); R[0][1] = -sin(angle);
    R[1][0] = sin(angle); R[1][1] = cos(angle);
    cout << "Matriz de rotación 45°:" << endl;
    R.print();
    cout << endl;
    // Vector de punto (1, 0)
    LAVector p(2);
    p[0] = 1; p[1] = 0;
    cout << "Punto original: "; p.print(); cout << endl;
    // Rotamos el punto
    LAVector p_rot = R * p;
    cout << "Punto rotado: "; p_rot.print(); cout << endl;
    return 0;
}
*/

// Main de prueba ejercicio 8 con entrada del usuario
int main() {
    // Capa con 3 entradas y 2 salidas
    NeuralLayer layer(3, 2, true); // false = usa sigmoide , true = usa ReLU
    // Definimos pesos y sesgos manualmente
    // salida1 = σ(0.2*x1 + 0.4*x2 + 0.6*x3 + 0.5)
    // salida2 = σ(0.1*x1 + 0.3*x2 + 0.9*x3 + -0.3)
    layer.setWeight(0, 0, 0.2); layer.setWeight(0, 1, 0.4); layer.setWeight(0, 2, 0.6);
    layer.setWeight(1, 0, 0.1); layer.setWeight(1, 1, 0.3); layer.setWeight(1, 2, 0.9);
    layer.setBias(0, 0.5);
    layer.setBias(1, -0.3);
    // Vector de entrada (3 valores)
    LAVector input(3);
    input[0] = 1.0; input[1] = 2.0; input[2] = 3.0;
    cout << "Entrada: "; input.print(); cout << endl;
    // Propagación hacia adelante
    LAVector output = layer.forward(input);
    cout << "Salida de la capa: "; output.print(); cout << endl;
    return 0;
}