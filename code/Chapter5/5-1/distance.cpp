#include <iostream>
#include <cmath>

using namespace std;

double square(double x) {
    return x * x;
}

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(square(x1 - x2) + square(y1 - y2));
}

int main() {
    double x1, y1, x2, y2;
    cout << "Enter (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter (x2, y2): ";
    cin >> x2 >> y2;

    cout << "Distance: " << distance(x1, y1, x2, y2) << endl;
    return 0;
}