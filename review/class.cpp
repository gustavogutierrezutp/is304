#include <cmath>
#include <iostream>

using namespace std;

class Point {
private:
  double x;
  double y;
  double z;

public:
  Point() {
    x = 0.0;
    y = 0.0;
    z = 0.0;
  }

  Point(double c) {
    x = c;
    y = c;
    z = c;
  }

  double distance(Point *other) {
    double dx = x - other->x;
    double dy = y - other->y;
    double dz = z - other->z;
    return sqrt(dx * dx + dy * dy + dz * dz);
  }

  void print() {
    cout << "Point(" << x << ", " << y << ", " << z << ")" << endl;
  }
};

int main() {
  Point p;
  Point q(1.0);
  p.print();
  q.print();
  double d = p.distance(&q);
  cout << "Distance: " << d << endl;
  return 0;
}