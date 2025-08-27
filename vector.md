# 📘 Vector Practice Exercises

These exercises will help you practice using the custom `Vector<T>` implementation.

---

### 1. **Sum of Elements**
Write a function that takes a `Vector<int>` and returns the sum of all elements.  

**Signature:**
```cpp
int sumVector(const Vector<int>& v);
```
### 2. Reverse a Vector

Write a function that takes a Vector<int> and returns a new Vector<int> with elements in reverse order.

**Signature:**
```cpp
Vector<int> reverseVector(const Vector<int>& v);
```

### 3. **Filter Even Numbers**

Write a function that takes a `Vector<int>` and returns a new vector containing only the even numbers.

**Signature:**
```cpp
Vector<int> filterEven(const Vector<int>& v);
```

### 4. Dot Product of Two Vectors

Write a function that computes the dot product of two `Vector<int>` (element-wise multiplication and sum).
If the vectors don’t have the same size, throw an exception or print an error.

**Signature:**
```cpp
int dotProduct(const Vector<int>& a, const Vector<int>& b);
```

### 5. Dynamic Growth Test

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