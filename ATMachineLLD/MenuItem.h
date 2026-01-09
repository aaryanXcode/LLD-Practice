#ifndef MENU_ITEM
#define MENU_ITEM

#include "MenuComponent.h"
#include <string>
#include <iostream>

class MenuItem : public MenuComponent {
private:
    int id;
    std::string name;

public:
    MenuItem(int id, const std::string& name) : id(id), name(name) {}

    void display() override {
        std::cout << id << ". " << name << std::endl;
    }

    int getId() override {
        return id;
    }
};

#endif