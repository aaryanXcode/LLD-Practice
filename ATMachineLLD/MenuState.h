
#ifndef MENU_STATE
#define MENU_STATE

#include "IATMState.h"
#include "Menu.h"
#include "MenuItem.h"
#include <iostream>

class ATM;

class MenuState : public IATMState {
private:
    Menu* menu;

public:
    MenuState() {
        menu = new Menu();
        menu->add(new MenuItem(1, "Withdraw Cash"));
        menu->add(new MenuItem(2, "Check Balance"));
        menu->add(new MenuItem(3, "Eject Card"));
    }

    void selectOption(ATM* atm, int option) override {
        if (option == -1) {
            menu->display();
            return;
        }

        switch (option) {
            case 1:
                atm->setState(atm->getWithdrawState());
                break;
            case 2:
                atm->setState(atm->getBalanceCheckState());
                break;
            case 3:
                atm->setState(atm->getEjectCardState());
                break;
            default:
                std::cout << "Invalid option\n";
                menu->display();
        }
    }

    void insertCard(ATM*) override {}
    void enterPin(ATM*, int) override {}
    void withdrawAmount(ATM*, int) override {}
    void checkBalance(ATM*) override {}
    void ejectCard(ATM* atm) override {
        atm->setState(atm->getIdleState());
    }
    void balanceCheckState(ATM*) override {}
};

#endif