#pragma once
#include "Burger.h"
#include <iostream>
using namespace std;
class PremiumWheatBurger:public Burger{
    void prepare() override{
        cout<<"preparing premium wheat burger"<<endl;
    }
};