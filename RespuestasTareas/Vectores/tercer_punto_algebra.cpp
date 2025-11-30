#include <iostream>
#include <cmath>
using namespace std;

// ---------------------------------------------------------
// Clase plantilla AlgebraVector
// ---------------------------------------------------------
template <typename V>
class AlgebraVector {
private:
    V* storage;
    int size;

public:
    AlgebraVector(int s) : size(s) {
        storage = new V[size];
        for (int i = 0; i < size; ++i)
            storage[i] = V(0);
    }

    AlgebraVector(int s, const V init[]) : size(s) {
        storage = new V[size];
        for (int i = 0; i < size; ++i)
            storage[i] = init[i];
    }

    AlgebraVector(const AlgebraVector& other) : size(other.size) {
        storage = new V[size];
        for (int i = 0; i < size; ++i)
            storage[i] = other.storage[i];
    }

    ~AlgebraVector() {
        delete[] storage;
    }

    V& operator[](int idx) {
        return storage[idx];
    }

    const V& operator[](int idx) const {
        return storage[idx];
    }

    AlgebraVector<V> SumaVectores(const AlgebraVector& o) const {
        AlgebraVector<V> r(size);
        for (int i = 0; i < size; ++i)
            r[i] = storage[i] + o.storage[i];
        return r;
    }

    AlgebraVector<V> MultiplicacionEscalar(double escalar) const {
        AlgebraVector<V> r(size);
        for (int i = 0; i < size; ++i)
            r[i] = storage[i] * escalar;
        return r;
    }

    V ProductoPunto(const AlgebraVector& o) const {
        V sum = V(0);
        for (int i = 0; i < size; ++i)
            sum += storage[i] * o.storage[i];
        return sum;
    }

    V Magnitud() const {
        V sum = V(0);
        for (int i = 0; i < size; ++i)
            sum += storage[i] * storage[i];
        return sqrt(sum);
    }

    void ImprimirVector() const {
        for (int i = 0; i < size; ++i)
            cout << storage[i] << " ";
    }
};


// ---------------------------------------------------------
// Clase MatrizAlgebra
// ---------------------------------------------------------
class MatrizAlgebra {
private:
    int filas, columnas;
    AlgebraVector<double>** storage;

public:
    MatrizAlgebra(int f, int c) : filas(f), columnas(c) {
        storage = new AlgebraVector<double>*[filas];
        for (int i = 0; i < filas; ++i)
            storage[i] = new AlgebraVector<double>(columnas);
    }

    MatrizAlgebra(int f, int c, const double init[])
        : filas(f), columnas(c) {
        storage = new AlgebraVector<double>*[filas];
        for (int i = 0; i < filas; ++i)
            storage[i] = new AlgebraVector<double>(
                columnas, &init[i * columnas]);
    }

    MatrizAlgebra(const MatrizAlgebra& o)
        : filas(o.filas), columnas(o.columnas) {
        storage = new AlgebraVector<double>*[filas];
        for (int i = 0; i < filas; ++i)
            storage[i] = new AlgebraVector<double>(*o.storage[i]);
    }

    ~MatrizAlgebra() {
        for (int i = 0; i < filas; ++i)
            delete storage[i];
        delete[] storage;
    }

    // Multiplicación matriz-vector (alias en español)
    AlgebraVector<double> MultiplicarPorVector(const AlgebraVector<double>& vec) const {
        AlgebraVector<double> result(filas);
        for (int i = 0; i < filas; ++i) {
            double sum = 0;
            for (int j = 0; j < columnas; ++j)
                sum += (*storage[i])[j] * vec[j];
            result[i] = sum;
        }
        return result;
    }

    void ImprimirMatriz() const {
        for (int i = 0; i < filas; ++i) {
            storage[i]->ImprimirVector();
            cout << endl;
        }
    }
};


// ---------------------------------------------------------
// Clase NeuralLayer
// ---------------------------------------------------------
class NeuralLayer {
private:
    int input_size, output_size;
    MatrizAlgebra weights;               
    AlgebraVector<double> biases;        

public:
    NeuralLayer(int input_sz, int output_sz,
                const double w_init[], const double b_init[])
        : input_size(input_sz),
          output_size(output_sz),
          weights(output_sz, input_sz, w_init),
          biases(output_sz, b_init) {}

    AlgebraVector<double> forward_sig(const AlgebraVector<double>& x) const {
        AlgebraVector<double> Z = weights.MultiplicarPorVector(x);
        for (int i = 0; i < output_size; ++i) {
            Z[i] += biases[i];
            Z[i] = 1.0 / (1.0 + exp(-Z[i]));
        }
        return Z;
    }

    AlgebraVector<double> forward_relu(const AlgebraVector<double>& x) const {
        AlgebraVector<double> Z = weights.MultiplicarPorVector(x);
        for (int i = 0; i < output_size; ++i) {
            Z[i] += biases[i];
            Z[i] = (Z[i] > 0.0 ? Z[i] : 0.0);
        }
        return Z;
    }
};


// ---------------------------------------------------------
// Función principal: prueba de la capa con 3→2
// ---------------------------------------------------------
int main() {
    double w_init[2 * 3] = {
        0.2, -0.5, 1.0,
       -1.5,  2.0, 0.7
    };

    double b_init[2] = { 0.1, -0.3 };
    double x_init[3] = { 1.0, 0.0, -1.0 };

    AlgebraVector<double> input(3, x_init);
    NeuralLayer layer(3, 2, w_init, b_init);

    cout << "Entrada: ";
    input.ImprimirVector();
    cout << "\n\n";

    auto out_sig = layer.forward_sig(input);
    cout << "Salida (sigmoid): ";
    out_sig.ImprimirVector();
    cout << "\n\n";

    auto out_relu = layer.forward_relu(input);
    cout << "Salida (ReLU):    ";
    out_relu.ImprimirVector();
    cout << "\n";

    return 0;
}
