#ifndef EJECTCARD_STATE
#define EJECTCARD_STATE

#include "IATMState.h"
#include <iostream>

class ATM;

class EjectCardState : public IATMState{
    public:
        void insertCard(ATM*) override {}

        void enterPin(ATM* atm, int pin) override {}

        void selectOption(ATM*, int) override {}
        void withdrawAmount(ATM*, int) override {}
        void checkBalance(ATM*) override {}

        void ejectCard(ATM* atm) override {
            std::cout << "Card ejected\n";
            atm->setState(atm->getIdleState());
        }

        void balanceCheckState(ATM*) override {}
};

#endif