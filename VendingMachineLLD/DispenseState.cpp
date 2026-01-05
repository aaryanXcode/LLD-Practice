#include "DispenseState.h"
#include "VendingMachine.h"
#include <iostream>

void DispenseState::insertCoin(VendingMachine* /*machine*/, int /*coin*/) {
    std::cout << "Dispensing in progress. Please wait." << std::endl;
}

void DispenseState::selectItem(VendingMachine* /*machine*/) {
    std::cout << "Dispensing in progress. Please wait." << std::endl;
}

void DispenseState::returnCoin(VendingMachine* /*machine*/) {
    std::cout << "Cannot return coin after selection. Dispensing..." << std::endl;
}

void DispenseState::dispense(VendingMachine* machine) {
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

void DispenseState::refill(VendingMachine* /*machine*/, int /*quantity*/) {
    std::cout << "Cannot refill during dispensing." << std::endl;
}
