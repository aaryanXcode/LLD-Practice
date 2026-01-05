#ifndef DISPENSE_STATE_H
#define DISPENSE_STATE_H

#include "IVendingMachineState.h"

class DispenseState : public IVendingMachineState {
public:
    void insertCoin(VendingMachine* machine, int coin) override;
    void selectItem(VendingMachine* machine) override;
    void returnCoin(VendingMachine* machine) override;
    void dispense(VendingMachine* machine) override;
    void refill(VendingMachine* machine, int quantity) override;
};

#endif
