#include "VendingMachine.h"
int main() {
    VendingMachine machine(2, 10); // 2 items, each 10 coins

    machine.insertCoin(5);        // Not enough
    machine.insertCoin(5);        // Total 10
    machine.selectItem();         // Should dispense
    machine.insertCoin(10);
    machine.selectItem();         // Dispenses again
    machine.insertCoin(10);       // Machine is now sold out
    machine.selectItem();         // Should say sold out
    machine.refill(3);            // Back to NoCoinState
}
