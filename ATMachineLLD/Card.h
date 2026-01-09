#ifndef CARD
#define CARD

#include "Account.h"
class Card {
private:
    Account* account;

public:
    Card(Account* account) : account(account) {}

    Account* getAccount() {
        return account;
    }
};

#endif