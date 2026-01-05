#include "HasCoinState.h"
#include "VendingMachine.h"
#include <iostream>

void HasCoinState::insertCoin(VendingMachine* machine, int coin) {
    machine->setInsertedCoins(machine->getInsertedCoins() + coin);
    std::cout << "Coin inserted: " << coin << ". Total: " << machine->getInsertedCoins() << std::endl;
}

void HasCoinState::selectItem(VendingMachine* machine) {
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

void HasCoinState::returnCoin(VendingMachine* machine) {
    int totalCoins = machine->getInsertedCoins();
    std::cout << "Returning " << totalCoins << " coins." << std::endl;
    machine->setInsertedCoins(0);
    machine->setState(machine->getNoCoinState());
}

void HasCoinState::dispense(VendingMachine* machine) {
    machine->setState(machine->getDispenseState());
    std::cout << "machine is set to dispense mode!" << std::endl;
}

void HasCoinState::refill(VendingMachine* machine, int quantity) {
    machine->incrementItemCount(quantity);
    std::cout << "Machine refilled by " << quantity << " items." << std::endl;
}
