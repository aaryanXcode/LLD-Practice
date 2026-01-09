#ifndef ATM_STATE.h
#define ATM_STATE.h

class IATMState{
    public:
        virtual void IdleState(ATM* machine, int balance) = 0;
        virtual void NoCashState(ATM* machine) = 0;
        virtual void WithDrawState(ATM* machine, int amount) = 0;
        virtual void CardInsertedState(ATM* machine) = 0;
        virtual void PinInsertState(ATM* machine, int pin) = 0;
        virtual void MenuState(ATM* machine);
        virtual void WithDrawState(ATM* machine, int amount) = 0;
        virtual void BalanceCheckState(ATM* machine) = 0;
        virtual void EjectCardState(ATM* machine) = 0;
        virtual ~IATMState()=0;



}

#endif