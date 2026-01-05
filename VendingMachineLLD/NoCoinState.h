#ifndef NOCOIN_STATE_H
#define NOCOIN_STATE_H

#include "IVendingMachineState.h"

class NoCoinState : public IVendingMachineState {
public:
    NoCoinState() = default;

    void insertCoin(VendingMachine* machine, int coin) override;
    void selectItem(VendingMachine* machine) override;
    void returnCoin(VendingMachine* machine) override;
    void dispense(VendingMachine* machine) override;
    void refill(VendingMachine* machine, int quantity) override;
};

#endif
