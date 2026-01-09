#include "ATM.h"
#include "StatesHeader.h"
#include "CashDispenser.h"

ATM::ATM(CashDispenser* dispenser)
    : cashDispenser(dispenser),
      atmBalance(dispenser->getTotalCash()),
      currentCard(nullptr)
{
    idleState = new IdleState();
    noCashState = new NoCashState();
    cardInsertedState = new CardInsertedState();
    pinInsertedState = new PinInsertedState();
    menuState = new MenuState();
    withdrawState = new WithdrawState();
    balanceCheckState = new BalanceCheckState();
    ejectCardState = new EjectCardState();

    currentState = (atmBalance > 0) ? idleState : noCashState;
}

void ATM::setState(IATMState* state) {
    currentState = state;
}

IATMState* ATM::getCurrentState() { return currentState; }

IATMState* ATM::getIdleState() { return idleState; }
IATMState* ATM::getNoCashState() { return noCashState; }
IATMState* ATM::getCardInsertedState() { return cardInsertedState; }
IATMState* ATM::getPinInsertedState() { return pinInsertedState; }
IATMState* ATM::getMenuState() { return menuState; }
IATMState* ATM::getWithdrawState() { return withdrawState; }
IATMState* ATM::getBalanceCheckState() { return balanceCheckState; }
IATMState* ATM::getEjectCardState() { return ejectCardState; }

bool ATM::hasSufficientCash(int amount) {
    return atmBalance >= amount;
}

void ATM::deductCash(int amount) {
    atmBalance -= amount;
}

int ATM::getATMBalance() {
    return atmBalance;
}

CashDispenser* ATM::getCashDispenser() {
    return cashDispenser;
}

void ATM::insertCard(Card* card) {
    currentCard = card;
    currentState->insertCard(this);
}

void ATM::ejectCard() {
    currentCard = nullptr;
}

Card* ATM::getCurrentCard() {
    return currentCard;
}
