#pragma once
#include "Burger.h"
#include <iostream>
using namespace std;
class StandardWheatBurger:public Burger{
    void prepare() override{
        cout<<"preparing standard wheat burger"<<endl;
    }
};