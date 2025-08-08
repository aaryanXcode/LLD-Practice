#pragma once
#include<iostream>
#include "Pizza.h"
using namespace std;

class NonVegPizza:public Pizza{
    public:
        void getPrice() override{
            cout<<"total price:400"<<endl;
        }

        void prepare() override {
            cout<<"Prepairing Non veg pizza"<<endl;
        }
};