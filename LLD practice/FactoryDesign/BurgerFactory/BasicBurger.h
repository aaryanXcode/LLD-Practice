#pragma once
#include "Burger.h"
#include <iostream>
using namespace std;
class BasicBurger:public Burger{
    void prepare() override{
        cout<<"preparing basic burger"<<endl;
    }
};