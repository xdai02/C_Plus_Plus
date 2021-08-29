#include <iostream>

using namespace std;

class User {
public:
    User();
    User(const User& user);
    ~User();
    void printDataAddress();

private:
    int *data;
};

User::User() {
    this->data = new int;
}

User::User(const User& user) {
    this->data = new int;
    *(this->data) = *(user.data);
}

User::~User() {
    delete data;
    data = nullptr;
}

void User::printDataAddress() {
    cout << data << endl;
}

int main() {
    User user1;
    user1.printDataAddress();
    User user2(user1);
    user2.printDataAddress();  
    return 0;
}