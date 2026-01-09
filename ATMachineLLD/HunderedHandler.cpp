#include "HunderedHandler.h"
#include "CashDispenser.h"
#include <algorithm>
#include <iostream>

bool HundredHandler::dispense(int& amount, CashDispenser* dispenser) {
    int needed = amount / 100;
    int available = dispenser->getAvailableNotes(100);
    int use = std::min(needed, available);

    if (use > 0) {
        dispenser->useNotes(100, use);
        amount -= use * 100;
        std::cout << "Dispensed " << use << " x 100\n";
    }

    return amount == 0;
}
