#include <iostream>
#include <string>

using namespace std;

class User {
public:
    User(int id, string name) : id(id), name(name) {
        totalUsers++;
    }

    static int getTotalUsers() {
        return totalUsers;
    }

private:
    static int totalUsers;
    int id;
    string name;
};

int User::totalUsers = 0;       // 初始用户数量

int main() {
    cout << User::getTotalUsers() << endl;
    for(int i = 0; i < 10; i++) {
        User user(i, "User-" + to_string(i));
    }
    cout << User::getTotalUsers() << endl;
    return 0;
}