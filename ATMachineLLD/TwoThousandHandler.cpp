#include "TwoThousandHandler.h"
#include "CashDispenser.h"
#include <algorithm>
#include <iostream>

bool TwoThousandHandler::dispense(int& amount, CashDispenser* dispenser) {
    int needed = amount / 2000;
    int available = dispenser->getAvailableNotes(2000);
    int use = std::min(needed, available);

    if (use > 0) {
        dispenser->useNotes(2000, use);
        amount -= use * 2000;
        std::cout << "Dispensed " << use << " x 2000\n";
    }
    return next ? next->dispense(amount, dispenser) : amount == 0;
}
