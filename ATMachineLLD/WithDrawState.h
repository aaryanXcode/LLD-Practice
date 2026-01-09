
#ifndef WITHDRAW_STATE
#define WITHDRAW_STATE

#include "IATMState.h"
#include "Card.h"
#include "Account.h"
#include "CashDispenser.h"
#include <iostream>

class ATM;

class WithdrawState : public IATMState {
public:
    void withdrawAmount(ATM* atm, int amount) override {
        Card* card = atm->getCurrentCard();
        Account* account = card->getAccount();

        // 1. Account validation
        if (account->getBalance() < amount) {
            std::cout << "Insufficient account balance\n";
            atm->setState(atm->getMenuState());
            return;
        }

        // 2. ATM validation
        if (!atm->hasSufficientCash(amount)) {
            std::cout << "ATM has insufficient cash\n";
            atm->setState(atm->getMenuState());
            return;
        }

        // 3. Cash dispenser (denomination-level)
        CashDispenser* dispenser = atm->getCashDispenser();
        if (!dispenser->dispenseCash(amount)) {
            std::cout << "Unable to dispense exact amount\n";
            atm->setState(atm->getMenuState());
            return;
        }

        // 4. Debit AFTER successful dispense
        account->debit(amount);
        atm->deductCash(amount);

        std::cout << "Please collect your cash\n";

        // 5. Back to menu
        atm->setState(atm->getMenuState());
        atm->getCurrentState()->selectOption(atm, -1);
    }

    void insertCard(ATM*) override {}
    void enterPin(ATM*, int) override {}
    void selectOption(ATM*, int) override {}
    void checkBalance(ATM*) override {}
    void ejectCard(ATM*) override {}
    void balanceCheckState(ATM*) override {}
};


#endif