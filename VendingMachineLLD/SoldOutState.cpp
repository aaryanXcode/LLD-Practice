#include "SoldOutState.h"
#include "VendingMachine.h"
#include <iostream>

void SoldOutState::insertCoin(VendingMachine* /*machine*/, int /*coin*/) {
    std::cout << "Machine is sold out. Cannot accept coins." << std::endl;
}

void SoldOutState::selectItem(VendingMachine* /*machine*/) {
    std::cout << "Machine is sold out. No items available." << std::endl;
}

void SoldOutState::returnCoin(VendingMachine* machine) {
    if (machine->getInsertedCoins() > 0) {
        std::cout << "Returning " << machine->getInsertedCoins() << " coins." << std::endl;
        machine->setInsertedCoins(0);
    } else {
        std::cout << "No coin to return." << std::endl;
    }
}

void SoldOutState::dispense(VendingMachine* /*machine*/) {
    std::cout << "Machine is sold out. Nothing to dispense." << std::endl;
}

void SoldOutState::refill(VendingMachine* machine, int quantity) {
    machine->incrementItemCount(quantity);
    std::cout << "Machine refilled with " << quantity << " items." << std::endl;

    // Go to NoCoinState if we have stock now
    if (machine->getItemCount() > 0) {
        machine->setState(machine->getNoCoinState());
    }
}
