#include "java_programmer.h"
#include <iostream>

using namespace std;

JavaProgrammer::JavaProgrammer(string title) : Programmer(title) {}

void JavaProgrammer::work() {
    cout << "Android Development" << endl;
}