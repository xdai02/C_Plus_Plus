#include <iostream>
#include <string>

using namespace std;

class Complex {
    private:
    double real;
    double imag;

    public:
    Complex(double real=0, double imag=0) : real(real), imag(imag) {}

    Complex operator+(const Complex& c) {
        Complex complex;
        complex.real = this->real + c.real;
        complex.imag = this->imag + c.imag;
        return complex;
    }

    friend ostream& operator<<(ostream& os, const Complex& c);
};

ostream& operator<<(ostream& os, const Complex& c) {
    os << c.real << " + " << c.imag << "i";
    return os;
}

int main() {
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex result = c1 + c2;
    cout << result << endl;
    return 0;
}