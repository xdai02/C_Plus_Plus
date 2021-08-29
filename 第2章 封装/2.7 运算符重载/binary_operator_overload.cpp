#include <iostream>
#include <string>

using namespace std;

class Complex {
public:
    Complex(int real, int imaginary);
    string getNumber();
    Complex operator+(const Complex& c);

private:
    int real;
    int imaginary;
};

Complex::Complex(int real = 0, int imaginary = 0)
    : real(real), imaginary(imaginary) {
}

string Complex::getNumber() {
    return to_string(real) + "+" + to_string(imaginary) + "i";
}

Complex Complex::operator+(const Complex& c) {
    Complex complex;
    complex.real = this->real + c.real;
    complex.imaginary = this->imaginary + c.imaginary;
    return complex;
}

int main() {
    Complex c1(1, 2);
    Complex c2(8, 1);
    Complex result = c1 + c2;
    cout << result.getNumber() << endl;
    return 0;
}