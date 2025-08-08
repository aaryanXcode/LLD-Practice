#pragma once
#include "Burger.h"
#include <iostream>
using namespace std;
class StandardBurger:public Burger{
    void prepare() override{
        cout<<"preparing standard burger"<<endl;
    }
};