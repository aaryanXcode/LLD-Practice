#ifndef HUNDRED_HANDLER
#define HUNDRED_HANDLER

#include "CashHandler.h"

class CashDispenser;

class HundredHandler : public CashHandler {
public:
    using CashHandler::CashHandler;
    bool dispense(int& amount, CashDispenser* dispenser) override;
};

#endif