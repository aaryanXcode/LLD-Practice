#include "VendingMachine.h"
#include "NoCoinState.h"
#include "HasCoinState.h"
#include "DispenseState.h"
#include "SoldOutState.h"

VendingMachine::VendingMachine(int count, int price) : itemcount(count), itemprice(price), insertedcoins(0) {
    noCoinState = new NoCoinState();
    hasCoinState = new HasCoinState();
    dispenseState = new DispenseState();
    soldOutState = new SoldOutState();

    currentstate = (itemcount > 0) ? noCoinState : soldOutState;
}

VendingMachine::~VendingMachine() {
    delete noCoinState;
    delete hasCoinState;
    delete dispenseState;
    delete soldOutState;
}

void VendingMachine::insertCoin(int coin) {
    currentstate->insertCoin(this, coin);
}

void VendingMachine::selectItem() {
    currentstate->selectItem(this);
}

void VendingMachine::returnCoin() {
    currentstate->returnCoin(this);
}

void VendingMachine::dispense() {
    currentstate->dispense(this);
}

void VendingMachine::refill(int quantity) {
    currentstate->refill(this, quantity);
}
