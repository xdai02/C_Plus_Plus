#include <iostream>
#include <string>

using namespace std;

class BankAccount {
    private:
    const size_t ACCOUNT_DIGITS = 16;
    string owner;
    string account;
    double balance;

    public:
    BankAccount() {
        owner = "admin";
        account = "0000000000000000";
        balance = 0;
    }

    BankAccount(string owner, string account, double balance) {
        if (!owner.empty()) {
            this->owner = owner;
        }

        if (account.length() == ACCOUNT_DIGITS) {
            this->account = account;
        }

        if (balance >= 0) {
            this->balance = balance;
        }
    }

    void setOwner(string owner) {
        if (!owner.empty()) {
            this->owner = owner;
        }
    }

    string getOwner() {
        return owner;
    }

    void setAccount(string account) {
        if (account.length() == ACCOUNT_DIGITS) {
            this->account = account;
        }
    }

    string getAccount() {
        return account;
    }

    void setBalance(double balance) {
        if (balance >= 0) {
            this->balance = balance;
        }
    }

    double getBalance() {
        return balance;
    }

    bool deposit(double amount) {
        if (amount <= 0) {
            return false;
        }
        balance += amount;
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            return false;
        }
        balance -= amount;
        return true;
    }

    bool withdraw(double amount, double fee) {
        if (amount <= 0 || amount + fee > balance) {
            return false;
        }

        balance -= amount + fee;
        return true;
    }
};

int main() {
    BankAccount account1;
    cout << "Account 1 Owner: " << account1.getOwner() << endl;
    cout << "Account 1 Account: " << account1.getAccount() << endl;
    cout << "Account 1 Balance: " << account1.getBalance() << endl;

    BankAccount account2("Terry", "6250941006528599", 50);
    cout << "Account 2 Balance: " << account2.getBalance() << endl;

    account2.withdraw(20);
    cout << "Account 2 Balance: " << account2.getBalance() << endl;

    account2.withdraw(10, 1);
    cout << "Account 2 Balance: " << account2.getBalance() << endl;

    return 0;
}