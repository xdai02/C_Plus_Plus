#include <iostream>
#include <cmath>

using namespace std;

class Coordinate {
    private:
    double x;
    double y;

    public:
    Coordinate(double x, double y) : x(x), y(y) {}

    friend double distance(Coordinate &c1, Coordinate &c2);
};

double distance(Coordinate &c1, Coordinate &c2) {
    double delta_x = c1.x - c2.x;
    double delta_y = c1.y - c2.y;
    return sqrt(delta_x * delta_x + delta_y * delta_y);
}

int main() {
    Coordinate c1(0, 0);
    Coordinate c2(3, 4);
    cout << distance(c1, c2) << endl;
    return 0;
}