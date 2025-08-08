#pragma once
#include "IVendingMachineState.h"
#include "VendingMachine.h"
#include <iostream>

class SoldOutState : public IVendingMachineState {
public:
    SoldOutState() = default;

    void insertCoin(VendingMachine* machine, int coin) override {
        std::cout << "Machine is sold out. Cannot accept coins." << std::endl;
    }

    void selectItem(VendingMachine* machine) override {
        std::cout << "Machine is sold out. No items available." << std::endl;
    }

    void returnCoin(VendingMachine* machine) override {
        if (machine->getInsertedCoins() > 0) {
            std::cout << "Returning " << machine->getInsertedCoins() << " coins." << std::endl;
            machine->setInsertedCoins(0);
        } else {
            std::cout << "No coin to return." << std::endl;
        }
    }

    void dispense(VendingMachine* machine) override {
        std::cout << "Machine is sold out. Nothing to dispense." << std::endl;
    }

    void refill(VendingMachine* machine, int quantity) override {
        machine->incrementItemCount(quantity);
        std::cout << "Machine refilled with " << quantity << " items." << std::endl;

        // Go to NoCoinState if we have stock now
        if (machine->getItemCount() > 0) {
            machine->setState(machine->getNoCoinState());
        }
    }
};
