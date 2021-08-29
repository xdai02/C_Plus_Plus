#include <iostream>
#include <cmath>

using namespace std;

class Coordinate {
public:
    Coordinate(double x, double y) : x(x), y(y) {
    };

    friend double distance(Coordinate &c1, Coordinate &c2);

private:
    double x;
    double y;
};

double distance(Coordinate &c1, Coordinate &c2) {
    double deltaX = c1.x - c2.x;
    double deltaY = c1.y - c2.y;
    return sqrt(deltaX * deltaX + deltaY * deltaY);
}

int main() {
    Coordinate c1(3, 5);
    Coordinate c2(4, 6);
    cout << distance(c1, c2) << endl;
    return 0;
}