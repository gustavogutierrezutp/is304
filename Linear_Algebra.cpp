#include <iostream>
#include <math.h>

using namespace std;

class LAVector {
  
public:
    double x, y ,z;

    LAVector (double x, double y){
        this->x = x;
        this->y = y;
        this->z = 0;
    }

    LAVector(){
        x = 0;
        y = 0;
        z = 0;
    }

    LAVector(double x, double y, double z){
        this->x = x;
        this->y = y;
        this->z = z;
    }

    LAVector(const LAVector &other) {
        this->x = other.x;
        this->y = other.y;
        this->z = other.z;
    }

    double x_component() const {
        return x;
    }

    double y_component() const {
        return y;
    }

    double z_component() const {
        return z;
    }

    LAVector operator+(const LAVector &other) const {
        if (this->z == 0 && other.z == 0) {
            return LAVector(x + other.x, y + other.y);
        }
        return LAVector(x + other.x, y + other.y, z + other.z);
    }

    LAVector operator-(const LAVector &other) const {
        if (this->z == 0 && other.z == 0) {
            return LAVector(x - other.x, y - other.y);
        }
        return LAVector(x - other.x, y - other.y, z - other.z);
    }

    LAVector operator*(double scalar) const {
        if (this->z == 0) {
            return LAVector(x * scalar, y * scalar);
        }
        return LAVector(x * scalar, y * scalar, z * scalar);
    }

    double dot_product(const LAVector &other) const {
        if (this->z == 0 && other.z == 0) {
            return x * other.x + y * other.y;
        }
        return x * other.x + y * other.y + z * other.z;
    }

    double magnitude() const {
        if (this->z == 0) {
            return sqrt(x * x + y * y);
        }
        return sqrt(x * x + y * y + z * z);
    }

    LAVector normalization() const {
        double mag = magnitude();
        if (mag == 0) {
            cout << "Cannot normalize zero vector." << endl;
            return *this;
        }
        return *this * (1.0 / mag);
    }

};

void printVector(const LAVector &v) {
    if (v.z_component() == 0) {
        cout << "(" << v.x_component() << ", " << v.y_component() << ")" << endl;
    } else {
        cout << "(" << v.x_component() << ", " << v.y_component() << ", " << v.z_component() << ")" << endl;
    }
}

int main() {
    LAVector v1(1.0, 2.0, 3.0);
    cout << "v1: ";
    printVector(v1);

    LAVector v2(4.0, 5.0, 6.0);
    cout << "v2: ";
    printVector(v2);

    LAVector copy(v1);
    cout << "Copy of v1: ";
    printVector(copy);

    LAVector v3 = v1 + v2;
    cout << "Sum of v1 and v2: ";
    printVector(v3);

    LAVector v4 = v1 - v2;
    cout << "Difference of v1 and v2: ";
    printVector(v4);

    LAVector v5 = v1 * 2.0;
    cout << "v1 multiplied by 2: ";
    printVector(v5);

    double dot = v1.dot_product(v2);
    cout << "Dot product: " << dot << endl;

    double mag = v1.magnitude();
    cout << "Magnitude: " << mag << endl;

    LAVector v6 = v1.normalization();
    cout << "Normalized v1: ";
    printVector(v6);

    return 0;

}


