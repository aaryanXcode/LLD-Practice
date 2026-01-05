#ifndef VENDING_MACHINE_STATE_H
#define VENDING_MACHINE_STATE_H

#include "IVendingMachineState.h"
#include <iostream>

class NoCoinState;
class HasCoinState;
class DispenseState;
class SoldOutState;

class VendingMachine {
private:
    IVendingMachineState* currentstate;
    int itemcount;
    int itemprice;
    int insertedcoins;

    IVendingMachineState* noCoinState;
    IVendingMachineState* hasCoinState;
    IVendingMachineState* dispenseState;
    IVendingMachineState* soldOutState;

public:
    VendingMachine(int itemcount, int itemprice);
    ~VendingMachine();

    void setState(IVendingMachineState* state) { currentstate = state; }

    IVendingMachineState* getNoCoinState() { return noCoinState; }
    IVendingMachineState* getHasCoinState() { return hasCoinState; }
    IVendingMachineState* getDispenseState() { return dispenseState; }
    IVendingMachineState* getSoldOutState() { return soldOutState; }

    int getItemCount() const { return itemcount; }
    int getItemPrice() const { return itemprice; }
    int getInsertedCoins() const { return insertedcoins; }

    void incrementItemCount(int quantity) { itemcount += quantity; }
    void decrementItemCount() { if (itemcount > 0) itemcount--; }
    void setInsertedCoins(int coins) { insertedcoins = coins; }

    // --- Actions ---
    void insertCoin(int coin) { currentstate->insertCoin(this, coin); }
    void selectItem() { currentstate->selectItem(this); }
    void returnCoin() { currentstate->returnCoin(this); }
    void dispense() { currentstate->dispense(this); }
    void refill(int quantity) { currentstate->refill(this, quantity); }
};

#endif
