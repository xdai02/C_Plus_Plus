#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    Person(string name, int age);
    string toString();

private:
    string name;
    int age;
};

Person::Person(string name, int age) : name(name), age(age) {
    cout << "Person::Person(string, int)" << endl;
}

string Person::toString() {
    return "姓名：" + name + "，年龄：" + to_string(age);
}

int main() {
    Person person("小灰", 17);
    cout << person.toString() << endl;    
	return 0;
}