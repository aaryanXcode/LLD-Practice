#include "FiveHunderHandler.h"
#include "CashDispenser.h"
#include <algorithm>
#include <iostream>

bool FiveHundredHandler::dispense(int& amount, CashDispenser* dispenser) {
    int needed = amount / 500;
    int available = dispenser->getAvailableNotes(500);
    int use = std::min(needed, available);

    if (use > 0) {
        dispenser->useNotes(500, use);
        amount -= use * 500;
        std::cout << "Dispensed " << use << " x 500\n";
    }

    return next ? next->dispense(amount, dispenser) : amount == 0;
}
