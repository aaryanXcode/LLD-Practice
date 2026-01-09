#ifndef ACCOUNT
#define ACCOUNT

#include <string>

class Account {
private:
    std::string accountHolderName;
    int balance;

public:
    Account(int balance) : balance(balance) {}

    int getBalance() {
        return balance;
    }

    void debit(int amount) {
        balance -= amount;
    }
};

#endif