#include "CashDispenser.h"
#include "TwoThousandHandler.h"
#include "FiveHunderHandler.h"
#include "HunderedHandler.h"

CashDispenser::CashDispenser(int n2000, int n500, int n100)
    : note2000(n2000), note500(n500), note100(n100), chain(nullptr) {
    
    int total = n2000 * 2000 + n500 * 500 + n100 * 100;
    if (total <= 0) {
        throw std::runtime_error("Invalid cash configuration");
    }
    
    chain = new TwoThousandHandler(
                new FiveHundredHandler(
                    new HundredHandler(nullptr)
                )
            );
}

CashDispenser::~CashDispenser() {
    delete chain;
}

int CashDispenser::getTotalCash() {
    return note2000 * 2000 + note500 * 500 + note100 * 100;
}

bool CashDispenser::canDispense(int amount) {
    return amount <= getTotalCash();
}

bool CashDispenser::useNotes(int denomination, int count) {
    if (denomination == 2000 && note2000 >= count) {
        note2000 -= count;
        return true;
    }
    if (denomination == 500 && note500 >= count) {
        note500 -= count;
        return true;
    }
    if (denomination == 100 && note100 >= count) {
        note100 -= count;
        return true;
    }
    return false;
}

int CashDispenser::getAvailableNotes(int denomination) {
    if (denomination == 2000) return note2000;
    if (denomination == 500) return note500;
    if (denomination == 100) return note100;
    return 0;
}

bool CashDispenser::dispenseCash(int amount) {
    int remaining = amount;
    bool success = chain->dispense(remaining, this);
    return success && remaining == 0;
}

void CashDispenser::printDispensedNotes(std::map<int,int>& dispensed) {
    std::cout << "Dispensed Notes:\n";
    for (auto& it : dispensed) {
        std::cout << it.first << " x " << it.second << std::endl;
    }
}
