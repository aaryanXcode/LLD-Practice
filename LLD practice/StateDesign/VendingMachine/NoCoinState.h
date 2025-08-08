#pragma once
#include "IVendingMachineState.h"
class NoCoinState:public IVendingMachineState{
    void insertCoin(VendingMachine* machine, int coin) override {
        machine->setInsertedCoins(coin);
        std::cout << "Coin inserted: " << coin << std::endl;
        machine->setState(machine->getHasCoinState());
    }

    void selectItem(VendingMachine* machine) override {
        std::cout << "Insert coin first!" << std::endl;
    }

    void returnCoin(VendingMachine* machine) override {
        std::cout << "No coin to return!" << std::endl;
    }

    void dispense(VendingMachine* machine) override {
        std::cout << "Insert coin first!" << std::endl;
    }

    void refill(VendingMachine* machine, int quantity) override {
        machine->incrementItemCount(quantity);
        std::cout << "Machine refilled by " << quantity << " items." << std::endl;
    }
};