# 📘 Vector Practice Exercises

These exercises will help you practice using the custom `Vector<T>` implementation.

---
## Exercises Solutions
All the solutions for the 5 exercises are located in the **exercises** folder.

## Vectors as data structures

### 1. **Sum of Elements**
Write a function that takes a `Vector<int>` and returns the sum of all elements.  

**Signature:**
```cpp
int sumVector(const Vector<int>& v);
```
exercises
 1_sum_of_elements
 1sum.cpp

### 2. Reverse a Vector

Write a function that takes a Vector<int> and returns a new Vector<int> with elements in reverse order.

**Signature:**
```cpp
Vector<int> reverseVector(const Vector<int>& v);
```
exercises
 2_reverse_vector
 2reverse.cpp

### 3. **Filter Even Numbers**

Write a function that takes a `Vector<int>` and returns a new vector containing only the even numbers.

**Signature:**
```cpp
Vector<int> filterEven(const Vector<int>& v);
```
exercises
 3_filter
 3filter.cpp

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

exercises
 4_dynamic_growth
 4dynamic.cpp

### 5. Merge Two Sorted Vectors

Implement a function that merges two sorted Vector<int> into one sorted vector (like the merge step of MergeSort).

**Signature:**
```cpp
Vector<int> mergeSorted(const Vector<int>& a, const Vector<int>& b);
```
exercises
 5_merge_two
 5merge.cpp



## The linear algebra exercises were not completed.

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

