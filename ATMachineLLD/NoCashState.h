
#ifndef NO_CASH_STATE
#define NO_CASH_STATE

#include "IATMState.h"
#include <iostream>

class ATM;

class NoCashState : public IATMState{
    public:
        void insertCard(ATM*) override {
            std::cout << "ATM out of service\n";
        }

        void enterPin(ATM*, int) override {}
        void selectOption(ATM*, int) override {}
        void withdrawAmount(ATM*, int) override {}
        void checkBalance(ATM*) override {}
        void ejectCard(ATM*) override {}
        void balanceCheckState(ATM*) override {}
};

#endif