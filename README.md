This is the course on data structures taught at Universidad Tecnológica de
Pereira, Colombia. The course is taught in Spanish. In this site you will find
practical information and supplementary material for the course.

![Setting things up](docs/setup.md)


## Instructions

## Development environment

- Create a github repo
- Install wsl: https://learn.microsoft.com/en-us/windows/wsl/install
- Install Vscode: https://code.visualstudio.com/ 
- Clone your repository
- Reopen in WSL

### Just once!!!!
```sh
git config --global user.name "Your Name"
git config --global user.email "youremail@yourdomain.com"
```

```sh
sudo apt-get install build-essential clang-format
```

## Hello world

1. Create the file `pointers.cpp` and paste the following code:

```c++
#include <iostream>

using namespace std;

int main() {
    int x = 10;
    int* p = &x; // Pointer to x

    cout << "Value of x: " << x << endl; // Output: 10
    cout << "Address of x: " << &x << endl; // Output: Address of x
    cout << "Value at pointer p: " << *p << endl; // Output: 10
    cout << "Address stored in pointer p: " << p << endl; // Output: Address of x

    *p = 20; // Change value at pointer p

    cout << "New value of x: " << x << endl; // Output: 20
    return 0;
}
```

2. Open a terminal (Ctrl-ñ) and compile the file:

```sh
g++ -std=c++20 -o pointers pointers.cpp
```

This will create the file `pointers` (the executable!).  To run it:

```sh
./pointers
```


