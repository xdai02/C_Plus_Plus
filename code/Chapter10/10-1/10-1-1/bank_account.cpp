#include <iostream>
#include <string>

using namespace std;

class BankAccount {
public:
    string owner;
    string account;
    double balance;

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        balance -= amount;
    }
};

int main() {
    BankAccount account;
    account.owner = "Terry";
    account.account = "6250941006528599";
    account.balance = 50;

    cout << "Owner: " << account.owner << endl;
    cout << "Account: " << account.account << endl;
    cout << "Balance: " << account.balance << endl;

    account.deposit(100);
    cout << "Balance: " << account.balance << endl;

    account.withdraw(70);
    cout << "Balance: " << account.balance << endl;

    return 0;
}