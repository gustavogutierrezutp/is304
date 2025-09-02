
# Autor: Jesus David Grajales Montoya
# ID: 1089382804

# 📘 Vector Practice Exercises

These exercises will help you practice using the custom `Vector<T>` implementation.

---

## Vectors as data structures

### 1. **Sum of Elements**
Write a function that takes a `Vector<int>` and returns the sum of all elements.  

**Signature:**
```cpp
int sumVector(const Vector<int>& v);
```

**Solution:**
```cpp
int sumVector(const Vector<int>& v)
  {
    int sum = 0;
    for (unsigned int i = 0; i < v.size(); i++)
    {
        sum+=v[i];
    }

    return sum;
  }
```


### 2. Reverse a Vector

Write a function that takes a Vector<int> and returns a new Vector<int> with elements in reverse order.

**Signature:**
```cpp
Vector<int> reverseVector(const Vector<int>& v);
```

**Solution:**
```cpp
Vector<int> reverseVector(const Vector<int>& v)
{
    Vector<int> reversed(v.size()); 
    
    for (unsigned int i=0; i<v.size(); i++)
    {
        reversed.push_back(v[v.size() - i - 1]);
    }

    return reversed;
    
}
```



### 3. **Filter Even Numbers**

Write a function that takes a `Vector<int>` and returns a new vector containing only the even numbers.

**Signature:**
```cpp
Vector<int> filterEven(const Vector<int>& v);
```

**Solution:**
```cpp
Vector<int> filterEven(const Vector<int>& v)
{
    Vector<int> evens;

    for (unsigned int i = 0; i < v.size(); i++)
    {
        if (v[i] % 2 == 0)
        {
            evens.push_back(v[i]);
        }
    }

    return evens;
}
```


### 4. Dynamic Growth Test

Write a program that:

Creates an empty `Vector<int> u;`

Inserts numbers from 1 up to 1000 using `push_back`.

Every time the capacity changes, print the size and capacity.

Example Output (truncated):
```
Size: 6, Capacity: 7
Size: 8, Capacity: 10
Size: 11, Capacity: 15
...
```

**Solution:**
```cpp
void Dynamic_Growth_Test()
{
    Vector<int> test_v;
    unsigned int current_capacity = test_v.get_capacity();
    
    for (unsigned int i=0; i<1000; i++)
    {
        test_v.push_back(i);

        if (test_v.get_capacity() != current_capacity)
        {
            cout << "Capacity: " << test_v.get_capacity() << endl;
            cout << "Size: " << test_v.size() << endl;
            current_capacity = test_v.get_capacity();
            cout << endl;
        }


    }
}
```


### 5. Merge Two Sorted Vectors

Implement a function that merges two sorted Vector<int> into one sorted vector (like the merge step of MergeSort).

**Signature:**
```cpp
Vector<int> mergeSorted(const Vector<int>& a, const Vector<int>& b);
```

**Solution:**
```cpp
Vector<int> mergeSorted(const Vector<int>& a, const Vector<int>& b)
{
    Vector<int> merged(a.size() + b.size());
    unsigned int i = 0;
    unsigned int j = 0;

    while (i<a.size() and j<b.size())
    {

        if (a[i] < b[j])
        {
            merged.push_back(a[i]);
            i++;
        }
            
        else
        {
            merged.push_back(b[j]);
            j++;
        }
        
    }


    while(j<b.size())
        {
            merged.push_back(b[j]);
            j++;
        }
    

  
    while(i<a.size())
        {
            merged.push_back(a[i]);
            i++;
        }
       

    
    return merged;
}



```


**Feel free to check out the "vectors.cpp" file in case you want to test the methods or just to see the full implementation.**


## Vectors in the context of linear algebra

### 1. LAVector class
Write the `LAVector` class that represents a vector in the context of linear
algebra (not a a data structure that stores elements):
- Implement a constructor, a copy constructor an a destructor if needed.
- Implement `operator+` for vector addition
- Implement `operator-` for vector subtraction  
- Implement `operator*` for scalar multiplication
- Add a `dot_product()` method to compute the dot product between two vectors
- Add a `magnitude()` method to calculate the Euclidean norm
- **Challenge**: Implement vector normalization

**Complete LAVector class:**
```cpp
class LA_Vector
{
    private:

    float* arreglo;
    unsigned int ndim;


    public:

    LA_Vector()
    {
        arreglo = nullptr;
        ndim = 0;
    }


    LA_Vector(float* arreglo_extra, unsigned int size)
    {
        arreglo = new float[size];
        ndim = size;

        for (int i=0; i<size; i++)
        {
            arreglo[i] = arreglo_extra[i];
        }
    }

    LA_Vector(const LA_Vector &other) 
    {
        ndim = other.ndimensiones();

        arreglo = new float[other.ndimensiones()];

        for (unsigned int i = 0; i < other.ndimensiones(); i++) 
        {
            arreglo[i] = other.arreglo[i];
        }
    }
    

    ~LA_Vector()
    {
        delete[] arreglo;
    }

    unsigned int ndimensiones() const
    {
        return ndim;
    }

    float &operator[](unsigned int index) 
    { 
    return arreglo[index]; 
    }

    const float &operator[](unsigned int index) const 
    { 
        return arreglo[index]; 
    }

    float &at(unsigned int index) 
    {
        if (index >= ndim) 
        {
            throw out_of_range("Index out of range");
        }
    return arreglo[index];
    }

    const float &at(unsigned int index) const 
    {
      if (index >= ndim) 
      {
        throw out_of_range("Index out of range");
      }
    return arreglo[index];
    }

    LA_Vector& operator=(const LA_Vector& other)
    {
        if (this == &other) 
        {
            return *this;
        }

        delete[] arreglo; 
        ndim = other.ndimensiones();
        arreglo = new float[ndim]; 
        for (unsigned int i = 0; i < ndim; i++)
        {
            arreglo[i] = other.arreglo[i]; 
        }
        return *this;
    }

    void print()
    {   
        cout << "(";
        for (int i=0; i<ndim; i++)
        {
            if (i+1 == ndim)
            {
                cout << arreglo[i];
                break;
            }

            cout << arreglo[i] << " , ";
        }
        cout << ")";
        cout << endl;
    }


// Taller --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    
    LA_Vector operator+(const LA_Vector& v2) const
    {
        if (ndim == v2.ndimensiones())
        {
            float* arr_aux = new float[ndim];

            for (int i=0; i<ndim; i++)
            {
                arr_aux[i] = arreglo[i] + v2[i];
            }

            LA_Vector suma(arr_aux,ndim);
            delete[] arr_aux;
            return suma;

        }

        else
        {
            throw invalid_argument("Invalid number of dimensions.");
        }

    }



    LA_Vector operator-(const LA_Vector& v2) const
    {
        if (ndim == v2.ndimensiones())
        {
            float* arr_aux = new float[ndim];

            for (int i=0; i<ndim; i++)
            {
                arr_aux[i] = v2[i] - arreglo[i];
            }

            LA_Vector resta(arr_aux,ndim);
            delete[] arr_aux;
            return resta;

        }

        else
        {
            throw invalid_argument("Invalid number of dimensions.");
        }

    }



    LA_Vector operator*(const float scalar) const
    {
        float* arr_aux = new float[ndim];

        for (int i=0; i<ndim; i++)
        {
            arr_aux[i] = arreglo[i]*scalar;
        }

        LA_Vector escalar(arr_aux,ndim);
        delete[] arr_aux;
        return escalar;

    }



    float dot_product(const LA_Vector& v2) const
    {
        float acumulado = 0;

        if (ndim == v2.ndimensiones())
        {
            
            for (int i=0; i<ndim; i++)
            {
                acumulado = acumulado + (arreglo[i] * v2[i]);
            }

            return acumulado;

        }

        else
        {
            throw invalid_argument("Invalid number of dimensions.");
        }

    }



    float magnitude() const
    {
        float acumulado = 0;

        for (int i=0; i<ndim; i++)
        {
            acumulado = acumulado + (arreglo[i]*arreglo[i]);
        }

        return sqrt(acumulado);

    }

};

```


### Exercise 2: Matrix-Vector Multiplication Engine
Create a `Matrix` class that uses your `LAVector` class internally to store rows:
- Implement matrix-vector multiplication (Ax = b)
- Add methods for matrix addition and scalar multiplication
- Implement `transpose()` method
- **AI Connection**: Use this to implement a simple linear transformation for 2D point rotation

**Complete Matrix Class(includes linear transformation function):**
```cpp
class Matrix
{
    private:

    LA_Vector* datos;
    unsigned int filas;
    unsigned int columnas;


    public:

    Matrix(unsigned int f, unsigned int c) 
    {
        filas = f;
        columnas = c;
        datos = new LA_Vector[filas];

        for (unsigned int i = 0; i < filas; i++) 
        {
            float* ceros = new float[columnas];

            for (unsigned int j = 0; j < columnas; j++) 
            {
                ceros[j] = 0.0;
            }

            datos[i] = LA_Vector(ceros, columnas);
            delete[] ceros;
        }


    }

    ~Matrix() 
    {
        delete[] datos;
    }

    float& at(unsigned int i, unsigned int j) 
    {
        if (i >= filas || j >= columnas) 
        {
            throw out_of_range("Index out of range");
        }   

        return datos[i].at(j);
    }

    float& at(unsigned int i, unsigned int j) const
    {
        if (i >= filas || j >= columnas) 
        {
            throw out_of_range("Index out of range");
        }   

        return datos[i].at(j);
    }

    LA_Vector &operator[](unsigned int i) 
    { 
        return datos[i]; 
    }

    LA_Vector &operator[](unsigned int i) const 
    { 
        return datos[i]; 
    }

    unsigned int num_filas() const
    {
        return filas;
    }

    unsigned int num_columnas() const
    {
        return columnas;
    }


    void printm() const  
    {
        for (int i = 0; i < filas; i++) 
        {
            cout << "[ ";
        
            for (int j = 0; j < columnas; j++) 
            {
                cout << datos[i].at(j);

                if (j != columnas - 1) 
                    cout << " , ";
            }
            cout << " ]" << endl;
        }
    }

    LA_Vector Matrix_Vector_Mult(const LA_Vector& vector) const
    {
        float array_aux[filas];

        if(vector.ndimensiones() != columnas)
        {
            throw out_of_range("Invalid number of dimension");
        }

        else
        {

            for (int i=0; i<filas; i++)
            {
                array_aux[i] = datos[i].dot_product(vector);   
            }

        }
        
        LA_Vector result(array_aux,filas);
        return result;
    }

    Matrix operator+(const Matrix& matriz2)
    {   
        
        Matrix resultado(filas,columnas);

        if (matriz2.num_columnas() != columnas || matriz2.num_filas() != filas)
        {
            throw out_of_range("Invalid dimensions");
        }

        else
        {
            for (int i=0; i<filas; i++)
            {
                resultado[i] = datos[i] + matriz2[i];
            }
        }

        return resultado;
    }

    Matrix transpose() const
    {
        Matrix transpuesta(columnas,filas);

        for (int i=0; i<filas; i++)
        {
            for (int j=0; j<columnas; j++)
            {
                transpuesta[j].at(i) = datos[i].at(j);
            }
        }

        return transpuesta;
    }



};


LA_Vector simple_linear_2d_transformation(const LA_Vector& vector, float angle)
    {   
        Matrix matriz_rotacion(2,2);

        if (vector.ndimensiones() != 2)
        {
            throw out_of_range("Invalid dimensions. Make sure the vector has only 2 dimensions");
        }

        

        else
        {
            matriz_rotacion[0][0] = cos(angle);    matriz_rotacion[0][1] = sin(angle) * -1;
            matriz_rotacion[1][0] = sin(angle);    matriz_rotacion[1][1] = cos(angle);
        }

        LA_Vector result = matriz_rotacion.Matrix_Vector_Mult(vector);

        return result;

    }
```

### Notes:
As before, you can check the full code whenever you want. I just included the portion I considered most relevant. Also, I'm aware that the matrix implementation is missing some operators, which I skipped since my main focus was on covering the exercise requirements. In addition, I was not able to properly implement point 3 (Neural Network), so I decided not to include it in this homework.
