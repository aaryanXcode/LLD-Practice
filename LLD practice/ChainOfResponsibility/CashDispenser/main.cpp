#include "IHandler.h"
#include "ThousandHandler.h"
#include "HunderHandler.h"
#include "TwoHunderHandler.h"
#include "FiveHunderHandler.h"
int main(){
    IHandler* thousandhandler = new ThousandHandler(3);
    IHandler* hundered = new HunderHandler(5);
    IHandler* twohundered = new TwoHunderHandler(8);
    IHandler* fivehundered = new FiveHunderHandler(10);

    thousandhandler->setNextHandle(fivehundered);
    fivehundered->setNextHandle(twohundered);
    twohundered->setNextHandle(hundered);

    int amountToWithdraw = 4000;

    cout << "\nDispensing amount: ₹" << amountToWithdraw << endl;
    thousandhandler->dispense(amountToWithdraw);
    return 0;

}