#include <iostream>
#include <cmath>

using namespace std;

class LAvector
{
private:
    double *storage;
    unsigned int sz;
    unsigned int capacity;
    double policy;

public:
    LAvector()
    {
        storage = new double[5];
        sz = 0;
        policy = 1.5;
        capacity = 5;
    }

    LAvector(unsigned int c, double p = 1.5)
    {
        storage = new double[c];
        sz = 0;
        policy = p;
        capacity = c;
    }

    LAvector(const LAvector &other)
    {
        sz = other.sz;
        capacity = other.capacity;
        storage = new double[capacity];
        for (unsigned int i = 0; i < sz; i++)
        {
            storage[i] = other.storage[i];
        }
    }

    ~LAvector()
    {
        delete[] storage;
    }

    void push_back(const double &elem)
    {
        if (sz == capacity)
        {
            resize();
        }
        storage[sz] = elem;
        sz++;
    }

    int size() const
    {
        return sz;
    }

private:
    void resize()
    {
        capacity *= policy;
        double *new_storage = new double[capacity];
        for (unsigned int i = 0; i < sz; i++)
        {
            new_storage[i] = storage[i];
        }
        delete[] storage;
        storage = new_storage;
    }

    void pop_back()
    {
        sz--;
    }

public:
    const double &operator[](unsigned int index) const
    {
        return storage[index];
    }

    const double &at(unsigned int index) const
    {
        if (index >= sz)
        {
            throw out_of_range("Index out of range");
        }
        return storage[index];
    }

    LAvector operator+(const LAvector &other)
        const
    {
        if (other.sz != sz)
        {
            throw runtime_error("Vectors must be of the same dimension");
        }
        LAvector r;
        for (int i = 0; i < sz; i++)
        {
            double sum;
            sum = storage[i] + other[i];
            r.push_back(sum);
        }
        return r;
    }

    LAvector operator-(const LAvector &other) const
    {
        if (other.sz != sz)
        {
            throw runtime_error("Vectors must be of the same dimension");
        }
        LAvector r;
        for (int i = 0; i < sz; i++)
        {
            double sust;
            sust = storage[i] - other[i];
            r.push_back(sust);
        }
        return r;
    }

    LAvector operator*(const double scalar) const
    {
        LAvector r;
        for (int i = 0; i < sz; i++)
        {
            double mult;
            mult = scalar * storage[i];
            r.push_back(mult);
        }
        return r;
    }

    double dot_product(const LAvector a) const
    {
        if (a.sz != sz)
        {
            throw runtime_error("Vectors must be of the same dimension");
        }
        double product;
        for (int i = 0; i < sz; i++)
        {
            product += a[i] * storage[i];
        }
        return product;
    }

    double magnitude() const
    {
        double mag;
        for (int i = 0; i < sz; i++)
        {
            mag += storage[i] * storage[i];
        }
        mag = sqrt(mag);
        return mag;
    }

    LAvector normalize() const
    {
        double mag;
        mag = magnitude();
        LAvector n;
        for (int i = 0; i < sz; i++)
        {
            double norm_cord;
            norm_cord = storage[i] / mag;
            n.push_back(norm_cord);
        }
        return n;
    }
};

void printVector(const LAvector &v)
{
    for (unsigned int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

/*class Matrix
{
private:
    LAvector components;
    int n_cols;
    int n_rows;

public:
    Matrix()
    {
        n_cols = 0;
        n_rows = 0;
    }

    Matrix(const Matrix &other)
    {
        for (int i = 0; i < n_cols; i++)
        {
            components.push_back(other.components[i]);
        }
        n_cols = other.n_cols;
        n_rows = other.n_rows;
    }

    void push_vector(const LAvector &v){
        if (n_cols == 0){
            components.push_back(v);
            n_rows = v.size();
            n_cols ++;     
        } else if (v.size() != n_rows){
            throw runtime_error("Vectors must be of the same dimension");
        }        
    }

    void rows() const {
        return n_rows;
    }

    void columns() const {
        return n_cols;
    }

    LAvector multiply_vector(){

    }

    LAvector operator[](const int index) const {
        return components[index];
    }

    Matrix multiply_scalar(const double s){
        Matrix r;
        for (int i = 0; i < n_cols; i++){
            for (int j = 0; j < n_rows; j++){
                r[i][j] = components[i][j] * s;
            }
        }
        return r;
    }
};
*/

int main()
{
    LAvector v;
    LAvector w;
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    w.push_back(4);
    w.push_back(2);
    w.push_back(1);
    LAvector sum(v + w);
    cout << "V + W is ";
    printVector(sum);
    LAvector sust(v - w);
    cout << "V - W is ";
    printVector(sust);
    LAvector v_scalar(v * 4);
    cout << "V * 4 is ";
    printVector(v_scalar);
    double dot_p;
    dot_p = v.dot_product(w);
    cout << "Dot product between V and W is " << dot_p << endl;
    double mag;
    mag = v.magnitude();
    cout << "The magnitude of V is " << mag << endl;
    LAvector norm_v(v.normalize());
    cout << "The vector V normalized is ";
    printVector(norm_v);

    /*Matrix a;
    LAvector f;
    f.push_back(1);
    f.push_back(2);
    printVector(f);
    LAvector g;
    g.push_back(2);
    g.push_back(4);
     printVector(g);
    a.push_vector(f);
    a.push_vector(g);
    Matrix b(a.multiply_scalar(2));*/
}