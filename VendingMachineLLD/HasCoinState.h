#ifndef HASCOIN_STATE_H
#define HASCOIN_STATE_H

#include "IVendingMachineState.h"

class HasCoinState : public IVendingMachineState {
public:
    HasCoinState() = default;

    void insertCoin(VendingMachine* machine, int coin) override;
    void selectItem(VendingMachine* machine) override;
    void returnCoin(VendingMachine* machine) override;
    void dispense(VendingMachine* machine) override;
    void refill(VendingMachine* machine, int quantity) override;
};

#endif
