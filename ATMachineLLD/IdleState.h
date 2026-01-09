
#ifndef IDLE_STATE
#define IDLE_STATE

#include "IATMState.h"
#include <iostream>

class ATM;

class IdleState : public IATMState{
    public:
        void insertCard(ATM* atm) override {
            std::cout << "Card inserted\n";
            atm->setState(atm->getCardInsertedState());
        }

        void enterPin(ATM*, int) override { std::cout << "Insert card first\n"; }
        void selectOption(ATM*, int) override { std::cout << "Insert card first\n"; }
        void withdrawAmount(ATM*, int) override { std::cout << "Insert card first\n"; }
        void checkBalance(ATM*) override { std::cout << "Insert card first\n"; }
        void ejectCard(ATM*) override { std::cout << "No card to eject\n"; }
        void balanceCheckState(ATM*) override {}
};

#endif