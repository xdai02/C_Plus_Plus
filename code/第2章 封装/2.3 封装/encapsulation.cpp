#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    void setName(string name) {
        this->name = name;
    }

    string getName() {
        return name;
    }

    void setAge(int age) {
        this->age = age;
    }

    int getAge() {
        return age;
    }

private:
    string name;
    int age;
};

int main() {
	Person person;

    person.setName("小灰");
    person.setAge(17);

    cout << "姓名：" << person.getName() << endl;
    cout << "年龄：" << person.getAge() << endl;
	return 0;
}