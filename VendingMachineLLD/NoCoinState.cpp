#include "NoCoinState.h"
#include "VendingMachine.h"
#include <iostream>

void NoCoinState::insertCoin(VendingMachine* machine, int coin) {
    machine->setInsertedCoins(coin);
    std::cout << "Coin inserted: " << coin << std::endl;
    machine->setState(machine->getHasCoinState());
}

void NoCoinState::selectItem(VendingMachine* /*machine*/) {
    std::cout << "Insert coin first!" << std::endl;
}

void NoCoinState::returnCoin(VendingMachine* /*machine*/) {
    std::cout << "No coin to return!" << std::endl;
}

void NoCoinState::dispense(VendingMachine* /*machine*/) {
    std::cout << "Insert coin first!" << std::endl;
}

void NoCoinState::refill(VendingMachine* machine, int quantity) {
    machine->incrementItemCount(quantity);
    std::cout << "Machine refilled by " << quantity << " items." << std::endl;
}
