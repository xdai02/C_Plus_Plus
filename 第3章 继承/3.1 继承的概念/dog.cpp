#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    Animal(string name = "", int age = 0);
    void eat();
    string toString();

private:
    string name;
    int age;
};

Animal::Animal(string name, int age)
    : name(name), age(age) {
}

void Animal::eat() {
    cout << "eating" << endl;
}

string Animal::toString() {
    return "name: " + name + ", age: " + to_string(age);
}

class Dog : public Animal {
public:
    Dog(string name, int age, string type = "");
    void bite();
    string toString();

private:
    string type;
};

Dog::Dog(string name, int age, string type)
    : Animal(name, age), type(type) {
}

void Dog::bite() {
    cout << "biting" << endl;
}

string Dog::toString() {
    return Animal::toString() + ", type: " + type;
}

int main() {
    Dog dog("¹·×Ó", 3, "¹þÊ¿Ææ");
    dog.eat();
    dog.bite();
    cout << dog.toString() << endl;
    return 0;
}