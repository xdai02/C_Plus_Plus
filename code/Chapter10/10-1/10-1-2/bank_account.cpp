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
};

int main() {
    BankAccount account;
    account.setOwner("Terry");
    account.setAccount("6250941006528599");
    account.setBalance(50);

    cout << "Owner: " << account.getOwner() << endl;
    cout << "Account: " << account.getAccount() << endl;
    cout << "Balance: " << account.getBalance() << endl;

    account.deposit(100);
    cout << "Balance: " << account.getBalance() << endl;

    account.withdraw(70);
    cout << "Balance: " << account.getBalance() << endl;

    return 0;
}