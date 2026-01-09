#ifndef CASH_DISPENSER_H
#define CASH_DISPENSER_H

#include "CashHandler.h"
#include <stdexcept>
#include <map>
#include <iostream>

class TwoThousandHandler;
class FiveHundredHandler;
class HundredHandler;

class CashDispenser {
private:
    int note2000;
    int note500;
    int note100;

    CashHandler* chain;

public:
    CashDispenser(int n2000, int n500, int n100);
    ~CashDispenser();

    int getTotalCash();
    bool canDispense(int amount);
    bool useNotes(int denomination, int count);
    int getAvailableNotes(int denomination);
    bool dispenseCash(int amount);
    void printDispensedNotes(std::map<int,int>& dispensed);
};

#endif
