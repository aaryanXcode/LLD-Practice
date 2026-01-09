#ifndef BALANCE_CHECK
#define BALANCE_CHECK

#include "IATMState.h"
#include "Card.h"
#include "Account.h"
#include <iostream>

class ATM;

class BalanceCheckState : public IATMState {
public:
    void checkBalance(ATM* atm) override {
        Card* card = atm->getCurrentCard();
        if (!card) {
            std::cout << "No card present\n";
            atm->setState(atm->getIdleState());
            return;
        }

        Account* account = card->getAccount();
        std::cout << "Your Account Balance: " << account->getBalance() << std::endl;

        // After showing balance, return to menu
        atm->setState(atm->getMenuState());
        atm->getCurrentState()->selectOption(atm, -1); // show menu
    }

    void insertCard(ATM*) override {}
    void enterPin(ATM*, int) override {}
    void selectOption(ATM*, int) override {}
    void withdrawAmount(ATM*, int) override {}

    void ejectCard(ATM* atm) override {
        atm->ejectCard();
        atm->setState(atm->getIdleState());
    }

    void balanceCheckState(ATM*) override {}
};

#endif