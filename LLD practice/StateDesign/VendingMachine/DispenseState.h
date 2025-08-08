#pragma once
#include "IVendingMachineState.h"
#include "VendingMachine.h"
#include <iostream>

class DispenseState : public IVendingMachineState {
public:
    DispenseState() = default;

    void insertCoin(VendingMachine* machine, int coin) override {
        std::cout << "Dispensing in progress. Please wait." << std::endl;
    }

    void selectItem(VendingMachine* machine) override {
        std::cout << "Dispensing in progress. Please wait." << std::endl;
    }

    void returnCoin(VendingMachine* machine) override {
        std::cout << "Cannot return coin after selection. Dispensing..." << std::endl;
    }

    void dispense(VendingMachine* machine) override {
        if (machine->getItemCount() == 0) {
            std::cout << "Oops! Out of stock." << std::endl;
            machine->setState(machine->getSoldOutState());
            return;
        }

        std::cout << "Dispensing item..." << std::endl;

        // Decrement stock and reset coin
        machine->decrementItemCount();

        // Deduct price from inserted coins
        int change = machine->getInsertedCoins() - machine->getItemPrice();
        if (change > 0) {
            std::cout << "Returning change: " << change << std::endl;
        }
        machine->setInsertedCoins(0);

        // Determine next state
        if (machine->getItemCount() == 0) {
            std::cout << "Machine is now empty." << std::endl;
            machine->setState(machine->getSoldOutState());
        } else {
            machine->setState(machine->getNoCoinState());
        }
    }

    void refill(VendingMachine* machine, int quantity) override {
        std::cout << "Cannot refill during dispensing." << std::endl;
    }
};
