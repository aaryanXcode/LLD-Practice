#ifndef MENU
#define MENU

#include "MenuComponent.h"
#include <vector>
#include <iostream>

class Menu : public MenuComponent {
private:
    std::vector<MenuComponent*> items;

public:
    void add(MenuComponent* item) {
        items.push_back(item);
    }

    void display() override {
        std::cout << "---- ATM Menu ----\n";
        for (auto item : items) {
            item->display();
        }
    }

    int getId() override {
        return -1; // not used
    }
};

#endif