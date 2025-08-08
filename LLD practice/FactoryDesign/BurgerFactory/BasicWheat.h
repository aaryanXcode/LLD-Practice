#pragma once
#include "Burger.h"
#include <iostream>
using namespace std;
class BasicWheatBurger:public Burger{
    void prepare() override{
        cout<<"preparing basic wheat burger"<<endl;
    }
};