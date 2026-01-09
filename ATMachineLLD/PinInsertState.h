
#ifndef PININSERTED_STATE
#define PININSERTED_STATE

#include "IATMState.h"
#include <iostream>

class ATM;

class PinInsertedState : public IATMState{
    public:
        void selectOption(ATM* atm, int option) override {
            if (option == 1)
                atm->setState(atm->getWithdrawState());
            else
                atm->setState(atm->getBalanceCheckState());
        }

        void insertCard(ATM*) override {}
        void enterPin(ATM*, int) override {}
        void withdrawAmount(ATM*, int) override {}
        void checkBalance(ATM*) override {}
        void ejectCard(ATM* atm) override {
            atm->setState(atm->getIdleState());
        }
        void balanceCheckState(ATM*) override {}
};

#endif