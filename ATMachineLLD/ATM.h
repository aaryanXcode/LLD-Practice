#ifndef ATM_H
#define ATM_H

class IATMState;
class IdleState;
class NoCashState;
class EjectCardState;
class CardInsertedState;
class MenuState;
class PinInsertedState;
class WithdrawState;
class BalanceCheckState;

class Card;
class CashDispenser;

class ATM {
private:
    // State management
    IATMState* currentState;
    IATMState* idleState;
    IATMState* noCashState;
    IATMState* cardInsertedState;
    IATMState* pinInsertedState;
    IATMState* menuState;
    IATMState* withdrawState;
    IATMState* balanceCheckState;
    IATMState* ejectCardState;

    // Session data
    Card* currentCard;

    // Cash
    CashDispenser* cashDispenser;
    int atmBalance;

public:
    // Constructor
    ATM(CashDispenser* dispenser);

    // State control
    void setState(IATMState* state);
    IATMState* getCurrentState();

    // State getters
    IATMState* getIdleState();
    IATMState* getNoCashState();
    IATMState* getCardInsertedState();
    IATMState* getPinInsertedState();
    IATMState* getMenuState();
    IATMState* getWithdrawState();
    IATMState* getBalanceCheckState();
    IATMState* getEjectCardState();

    // Cash helpers
    bool hasSufficientCash(int amount);
    void deductCash(int amount);
    int getATMBalance();

    CashDispenser* getCashDispenser();

    // Card handling
    void insertCard(Card* card);
    void ejectCard();
    Card* getCurrentCard();
};

#endif
