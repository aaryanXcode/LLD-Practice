#ifndef IVENDING_MACHINE_STATE_H
#define IVENDING_MACHINE_STATE_H
class VendingMachine;
class IVendingMachineState{
    public:
        virtual void insertCoin(VendingMachine* machine, int coin) = 0;
        virtual void selectItem(VendingMachine* machine) = 0;
        virtual void returnCoin(VendingMachine* machine) = 0;
        virtual void dispense(VendingMachine* machine) = 0;
        virtual void refill(VendingMachine* machine, int quantity) = 0;
        virtual ~IVendingMachineState() {}
};
#endif