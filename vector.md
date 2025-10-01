# 📘 Vector Practice Exercises

These exercises will help you practice using the custom `Vector<T>` implementation.

---

## Vectors as data structures

### 1. **Sum of Elements**
Write a function that takes a `Vector<int>` and returns the sum of all elements.  

R/= **DESDE LA LINEA NUMERO 5 ESTA LA FUNCION SUMA VECTOR DEL ARCHIVO VECTOR.CPP**

**Signature:**
```cpp
int sumVector(const Vector<int>& v);
```
### 2. Reverse a Vector

Write a function that takes a Vector<int> and returns a new Vector<int> with elements in reverse order.

R/= **DESDE LA LINEA NUMERO 21 COMIENZA LA FUNCION REVERSE VECTOR EN EL ARCHIVO VECTOR.CPP**

**Signature:**
```cpp
Vector<int> reverseVector(const Vector<int>& v);
```

### 3. **Filter Even Numbers**

Write a function that takes a `Vector<int>` and returns a new vector containing only the even numbers.

**LINEA 32 ARCHIVO VECTOR.CPP**

**Signature:**
```cpp
Vector<int> filterEven(const Vector<int>& v);
```

### 4. Dynamic Growth Test **ARCHIVO DYNAMICGROWTHTEST.CPP**

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

### 5. Merge Two Sorted Vectors

Implement a function that merges two sorted Vector<int> into one sorted vector (like the merge step of MergeSort).

**Signature:**
```cpp
Vector<int> mergeSorted(const Vector<int>& a, const Vector<int>& b);
```

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

**Test Case**: Create two 3D vectors representing points in space and perform all operations.

### Exercise 2: Matrix-Vector Multiplication Engine
Create a `Matrix` class that uses your `LAVector` class internally to store rows:
- Implement matrix-vector multiplication (Ax = b)
- Add methods for matrix addition and scalar multiplication
- Implement `transpose()` method
- **AI Connection**: Use this to implement a simple linear transformation for 2D point rotation

**Test Case**: Rotate a set of 2D points by 45 degrees using matrix multiplication.

### Exercise 3: Neural Network Layer Implementation
Use your Vector class to implement a simple neural network layer:
- Create a `NeuralLayer` class that stores weights as a Vector of Vectors
- Implement forward propagation: output = activation(weights * input + bias)
- Use the sigmoid activation function: σ(x) = 1/(1 + e^(-x))
- **Challenge**: Implement ReLU activation as an alternative

**Test Case**: Create a layer with 3 inputs, 2 outputs, and process a sample input vector.

