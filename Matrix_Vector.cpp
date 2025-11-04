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

    //Needed this operator for matrix class.
    double operator[](int index) const {
        switch (index) {
            case 0: return x;
            case 1: return y;
            case 2: return z;
            default:
                cerr << "Invalid vector index." << endl;
                return 0;
        }
    }

};

class Matrix{
    private:
    LAVector rows[3];
    int rowCount;

public:
    Matrix() {
        rows[0] = LAVector();
        rows[1] = LAVector();
        rows[2] = LAVector();
        rowCount = 3;
    }

    Matrix(const LAVector &row1, const LAVector &row2) {
        rows[0] = row1;
        rows[1] = row2;
        rowCount = 2;
    }

    Matrix(const LAVector &row1, const LAVector &row2, const LAVector &row3) {
        rows[0] = row1;
        rows[1] = row2;
        rows[2] = row3;
        rowCount = 3;
    }

    int getRowCount() const {
        return rowCount;
    }

    LAVector getColumn(int index) const {
        if (index >= 0 && index < rowCount) {
            return LAVector(rows[0][index], rows[1][index], rows[2][index]);
        }
        cerr << "Invalid column index." << endl;
        return LAVector();
    }

    LAVector getRow(int index) const {
        if (index >= 0 && index < rowCount) {
            return rows[index];
        }
        cerr << "Invalid row index." << endl;
        return LAVector();
    }

    LAVector operator*(const LAVector &vec) const {
        if (vec.z_component() == 0) {
            return LAVector(
                rows[0].dot_product(vec),
                rows[1].dot_product(vec)
            );
        }
        return LAVector(
            rows[0].dot_product(vec),
            rows[1].dot_product(vec),
            rows[2].dot_product(vec)
        );
    }

    Matrix operator+(const Matrix &other) const {
        if (getRow(0).z_component() == 0 && other.getRow(0).z_component() == 0) {
            return Matrix(
                rows[0] + other.rows[0],
                rows[1] + other.rows[1]
            );
        }
        return Matrix(
            rows[0] + other.rows[0],
            rows[1] + other.rows[1],
            rows[2] + other.rows[2]
        );
    }

    Matrix operator*(double scalar) const {
        if (scalar == 0) {
            return Matrix();
        }
        if (rowCount == 2) {
            return Matrix(
                rows[0] * scalar,
                rows[1] * scalar
            );
        }
        else return Matrix(
            rows[0] * scalar,
            rows[1] * scalar,
            rows[2] * scalar
        );
    }

    Matrix operator*(const Matrix &other) const {
        if (rowCount == 2 && other.rowCount == 2) {
            return Matrix(
                LAVector(
                    rows[0].dot_product(other.getColumn(0)),
                    rows[0].dot_product(other.getColumn(1))
                ),
                LAVector(
                    rows[1].dot_product(other.getColumn(0)),
                    rows[1].dot_product(other.getColumn(1))
                )
            );
        }
        return Matrix(
            LAVector(
                rows[0].dot_product(other.getColumn(0)),
                rows[0].dot_product(other.getColumn(1)),
                rows[0].dot_product(other.getColumn(2))
            ),
            LAVector(
                rows[1].dot_product(other.getColumn(0)),
                rows[1].dot_product(other.getColumn(1)),
                rows[1].dot_product(other.getColumn(2))
            ),
            LAVector(
                rows[2].dot_product(other.getColumn(0)),
                rows[2].dot_product(other.getColumn(1)),
                rows[2].dot_product(other.getColumn(2))
            )
        );
    }

    Matrix transpose() const {
        if (getRow(0).z_component() == 0) {
            return Matrix(
                LAVector(rows[0].x_component(), rows[1].x_component(), 0),
                LAVector(rows[0].y_component(), rows[1].y_component(), 0)
            );
        }
        return Matrix(
            LAVector(rows[0].x_component(), rows[1].x_component(), rows[2].x_component()),
            LAVector(rows[0].y_component(), rows[1].y_component(), rows[2].y_component()),
            LAVector(rows[0].z_component(), rows[1].z_component(), rows[2].z_component())
        );
    }

};

void printMatrix(const Matrix &mat) {
    int rows = mat.getRowCount();
    for (int i = 0; i < rows; i++){
        if (mat.getRow(i).z_component() == 0) {
            cout << "(" 
                 << mat.getRow(i).x_component() << ", " 
                 << mat.getRow(i).y_component() << ")" << endl;
        } else {
            cout << "(" 
                 << mat.getRow(i).x_component() << ", " 
                 << mat.getRow(i).y_component() << ", " 
                 << mat.getRow(i).z_component() << ")" << endl;
        }
    }
}


void printVector(const LAVector &v) {
    if (v.z_component() == 0) {
        cout << "(" << v.x_component() << ", " << v.y_component() << ")" << endl;
    } else {
        cout << "(" << v.x_component() << ", " << v.y_component() << ", " << v.z_component() << ")" << endl;
    }
}

int main(){
    LAVector vec1(1, 2);
    LAVector vec2(3, 4);
    Matrix mat(vec1, vec2);

    cout << "\nYour Matrix is: " << endl;
    printMatrix(mat);

    cout << "\nThe resultant vector of your Matrix * vec1 is: " << endl;
    LAVector result = mat * vec1;
    printVector(result);

    Matrix mat2 = mat.transpose();
    cout << "\nYour Transposed Matrix is: " << endl;
    printMatrix(mat2);

    double scalar = 2.0;
    Matrix mat3 = mat * scalar;
    cout << "\nYour Scaled Matrix is: " << endl;
    printMatrix(mat3);

    Matrix rotationMatrix(
        LAVector(0.7071, -0.7071),
        LAVector(0.7071, 0.7071)
    );
    Matrix rotatedMatrix = mat * rotationMatrix;
    cout << "\nYour Matrix rotated 45 degrees is: " << endl;
    printMatrix(rotatedMatrix);

    return 0;
}