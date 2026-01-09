#ifndef CASH_HANDLER
#define CASH_HANDLER

class CashDispenser;

class CashHandler {
protected:
    CashHandler* next;

public:
    CashHandler(CashHandler* next = nullptr) : next(next) {}
    virtual bool dispense(int& amount, CashDispenser* dispenser) = 0;
    virtual ~CashHandler() { delete next; }
};


#endif