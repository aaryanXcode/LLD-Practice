#pragma once
#include "PizzaDecorator.h"
#include<iostream>
using namespace std;
class CapsicumDecorator: public PizzaDecorator{
    public:
        CapsicumDecorator(Pizza* p):PizzaDecorator(p){
            cout << " + Capsicum topping price 50rs\n";
        }

        // void prepare() override {
        //     PizzaDecorator::prepare();  // base
        //     cout << "Adding Capsicum topping\n";
        // }
       
};