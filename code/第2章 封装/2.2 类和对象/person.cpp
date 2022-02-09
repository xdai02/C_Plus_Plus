#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    string name;
    int age;

    void eat() {
        cout << "吃饭" << endl;
    }

    void sleep() {
        cout << "睡觉" << endl;
    }
};

int main() {
	Person person;

    person.name = "小灰";
    person.age = 17;
    cout << "姓名：" << person.name << endl;
    cout << "年龄：" << person.age << endl;

    person.eat();
    person.sleep();
	return 0;
}