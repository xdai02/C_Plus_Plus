#include <iostream>

using namespace std;

int main() {
    int num1, num2;
    char op;

    cout << "Enter an expression: ";
    cin >> num1 >> op >> num2;

    switch (op)
    {
    case '+':
        cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
        break;
    case '-':
        cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
        break;
    case '*':
        cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
        break;
    case '/':
        cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
        break;
    default:
        cout << "Error! Operator is not supported" << endl;
        break;
    }

    return 0;
}