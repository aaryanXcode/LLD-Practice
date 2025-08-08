#pragma once
#include "Burger.h"
#include <iostream>
using namespace std;
class PremiumBurger:public Burger{
    void prepare() override{
        cout<<"preparing premium burger"<<endl;
    }
};