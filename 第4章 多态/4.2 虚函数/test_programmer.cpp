#include <iostream>
#include "programmer.h"
#include "java_programmer.h"

using namespace std;

int main() {
    JavaProgrammer javaProgrammer;
    javaProgrammer.work();
    Programmer programmer = (Programmer)javaProgrammer;
    programmer.work();
    return 0;
}