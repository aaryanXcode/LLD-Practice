#ifndef TWOTHOUSAND_HANDLER
#define TWOTHOUSAND_HANDLER

#include "CashHandler.h"

class CashDispenser;

class TwoThousandHandler : public CashHandler {
public:
    using CashHandler::CashHandler;
    bool dispense(int& amount, CashDispenser* dispenser) override;
};

#endif