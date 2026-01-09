#ifndef IATMSTATE_H
#define IATMSTATE_H

class ATM;

class IATMState {
public:
    virtual void insertCard(ATM* atm) = 0;
    virtual void enterPin(ATM* atm, int pin) = 0;
    virtual void selectOption(ATM* atm, int option) = 0;
    virtual void withdrawAmount(ATM* atm, int amount) = 0;
    virtual void checkBalance(ATM* atm) = 0;
    virtual void ejectCard(ATM* atm) = 0;
    virtual void balanceCheckState(ATM* atm) = 0;
    virtual ~IATMState() = default;
};


#endif