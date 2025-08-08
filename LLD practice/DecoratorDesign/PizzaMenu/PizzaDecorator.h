#pragma once
#include "Pizza.h"
#include<iostream>
using namespace std;
class PizzaDecorator:public Pizza{
    Pizza* pizza;
    public:
        PizzaDecorator(Pizza* p) : pizza(p) {}

        void getPrice() override {
            pizza->getPrice(); // delegate
        }

        void prepare() override {
            pizza->prepare(); // delegate
        }

        virtual ~PizzaDecorator() {
            delete pizza;
        }
};