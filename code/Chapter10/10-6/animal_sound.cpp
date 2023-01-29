#include <iostream>
#include "dog.h"
#include "cat.h"

using namespace std;

int main() {
    Dog dog;
    Cat cat;

    cout << "Dog's sound: " << dog.sound() << endl;
    cout << "Cat's sound: " << cat.sound() << endl;

    return 0;
}