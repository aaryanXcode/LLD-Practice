#ifndef FIVEHUNDRED_HANDLER
#define FIVEHUNDRED_HANDLER

#include "CashHandler.h"

class CashDispenser;

class FiveHundredHandler : public CashHandler {
public:
    using CashHandler::CashHandler;
    bool dispense(int& amount, CashDispenser* dispenser) override;
};

#endif