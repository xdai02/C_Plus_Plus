#include <iostream>
#include <string>

using namespace std;

class User {
public:
    User(int id, string name);
    friend ostream& operator<<(ostream& out, const User& user);
    friend istream& operator>>(istream& in, User& user);

private:
    int id;
    string name;
};

User::User(int id = 0, string name = "")
    : id(id), name(name) {}

ostream& operator<<(ostream& out, const User& user) {
    out << "ID: " << to_string(user.id) << ", "
        << "name: " << user.name;
    return out;
}

istream& operator>>(istream& in, User& user) {
    cout << "Enter user ID: ";
    in >> user.id;
    cout << "Enter user name: ";
    in >> user.name;
    return in;
}

int main() {
    User user;
    cin >> user;
    cout << user;
    return 0;
}