#include "programmer.h"
#include <iostream>

using namespace std;

Programmer::Programmer(string title) : title(title) {}

void Programmer::work() {
    cout << "programming" << endl;
}