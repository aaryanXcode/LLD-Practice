#pragma once
#include "IVendingMachineState.h"
class HasCoinState:public IVendingMachineState{
    
    void insertCoin(VendingMachine* machine, int coin) override {
        machine->setInsertedCoins(machine->getInsertedCoins() + coin);
        std::cout << "Coin inserted: " << coin << ". Total: " << machine->getInsertedCoins() << std::endl;
    }
    void selectItem(VendingMachine* machine) override {
        if (machine->getInsertedCoins() >= machine->getItemPrice()) {
            std::cout << "Item selected." << std::endl;
            machine->setState(machine->getDispenseState());
            machine->dispense();  // Automatically dispense
        } else {
            std::cout << "Insufficient coins. Insert at least " 
                      << machine->getItemPrice() - machine->getInsertedCoins()
                      << " more coins." << std::endl;
        }
    }

    void returnCoin(VendingMachine* machine) override {
        int totalCoins = machine->getInsertedCoins();
        std::cout << "Returning " << totalCoins << " coins." << std::endl;
        machine->setInsertedCoins(0);
        machine->setState(machine->getNoCoinState());
    }

    void dispense(VendingMachine* machine) override {
        //now it is in has coin state then we can dispense
        machine->setState(machine->getDispenseState());
        std::cout << "machine is set to dispence mode!" << std::endl;
    }

    void refill(VendingMachine* machine, int quantity) override {
        machine->incrementItemCount(quantity);
        std::cout << "Machine refilled by " << quantity << " items." << std::endl;
    }
};