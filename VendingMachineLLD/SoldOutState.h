#ifndef SOLD_OUT_STATE_H
#define SOLD_OUT_STATE_H

#include "IVendingMachineState.h"

class SoldOutState : public IVendingMachineState {
public:
    SoldOutState() = default;

    void insertCoin(VendingMachine* machine, int coin) override;
    void selectItem(VendingMachine* machine) override;
    void returnCoin(VendingMachine* machine) override;
    void dispense(VendingMachine* machine) override;
    void refill(VendingMachine* machine, int quantity) override;
};

#endif