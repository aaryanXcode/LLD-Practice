#pragma once
#include "PizzaDecorator.h"
#include<iostream>
using namespace std;
class CornDecorator: public PizzaDecorator{
    public:
        CornDecorator(Pizza* p ):PizzaDecorator(p){
            //PizzaDecorator::getPrice();  // base we can use it if we want to add price in runtine
            cout << " + Corn topping price 50 rs\n";
        }
        // void prepare() override {
        //     PizzaDecorator::prepare();  // base
        //     cout << "Adding Corn topping\n";
        // }
};