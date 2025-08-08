#pragma once
#include<iostream>
#include "Pizza.h"
using namespace std;

class VegPizza:public Pizza{
    public:
        void getPrice() override{
            cout<<"total price: 300"<<endl;
        }

        void prepare() override {
            cout<<"Prepairing veg pizza"<<endl;
        }
};