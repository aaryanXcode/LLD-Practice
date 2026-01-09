
#ifndef CARD_INSERTED_STATE
#define CARD_INSERTED_STATE

#include "IATMState.h"
#include <iostream>

class ATM;

class CardInsertedState : public IATMState{
    public:
        void insertCard(ATM* atm) override {
            std::cout << "Card already inserted\n";
        }

        void enterPin(ATM* atm, int pin) override {
            std::cout << "PIN entered\n";
            atm->setState(atm->getPinInsertedState());
        }

        void ejectCard(ATM* atm) override {
            std::cout << "Card ejected\n";
            atm->ejectCard();
            atm->setState(atm->getIdleState());
        }

        void selectOption(ATM*, int) override {}
        void withdrawAmount(ATM*, int) override {}
        void checkBalance(ATM*) override {}
        void balanceCheckState(ATM*) override {}
};

#endif