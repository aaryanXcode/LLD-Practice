#pragma once
#include<iostream>
using namespace std;
class Truck:public Vehicle{
    public:
        void start() override{
            cout<<"creating basic truck"<<endl;
        }
};