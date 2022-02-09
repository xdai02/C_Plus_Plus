#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    Person(string name, int age);
    ~Person();

private:
    string name;
    int age;
};

Person::Person(string name, int age) : name(name), age(age) {
    cout << "Person::Person(string, int)" << endl;
}

Person::~Person() {
    cout << "Person::~Person()" << endl;
}

int main() {
	Person p1("小灰", 17);
    Person *p2 = new Person("小白", 21);
    delete p2;
	return 0;
}