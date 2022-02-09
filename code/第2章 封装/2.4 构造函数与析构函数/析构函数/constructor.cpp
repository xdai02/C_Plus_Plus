#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    Person();
    Person(string name, int age);
    string toString();

private:
    string name;
    int age;
};

// 无参构造函数
Person::Person() {
    cout << "Person::Person()" << endl;
}

// 有参构造函数
Person::Person(string name, int age) {
    cout << "Person::Person(string, int)" << endl;
    this->name = name;
    this->age = age;
}

string Person::toString() {
    return "姓名：" + name + "，年龄：" + to_string(age);
}

int main() {
	Person p1;
    Person p2("小灰", 17);
    cout << p2.toString() << endl;    
	return 0;
}