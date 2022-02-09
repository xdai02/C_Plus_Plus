#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    Person(const Person &p);
    Person(string name, int age);

private:
    string name;
    int age;
};

Person::Person(const Person &p) {
    cout << "Person::Person(const Person &)" << endl;
    this->name = p.name;
    this->age = p.age;
}

Person::Person(string name, int age) {
    cout << "Person::Person(string, int)" << endl;
    this->name = name;
    this->age = age;
}

int main() {
    Person p1("小灰", 17);
    Person p2(p1);
    Person p3 = p1;
	return 0;
}