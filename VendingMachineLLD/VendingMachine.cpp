#include "VendingMachine.h"
#include "NoCoinState.h"
#include "HasCoinState.h"
#include "DispenseState.h"
#include "SoldOutState.h"

VendingMachine::VendingMachine(int itemcount, int itemprice)
    : itemcount(itemcount), itemprice(itemprice), insertedcoins(0)
{
    noCoinState = new NoCoinState();
    hasCoinState = new HasCoinState();
    dispenseState = new DispenseState();
    soldOutState = new SoldOutState();

    currentstate = (itemcount > 0) ? noCoinState : soldOutState;
}

VendingMachine::~VendingMachine()
{
    delete noCoinState;
    delete hasCoinState;
    delete dispenseState;
    delete soldOutState;
}
