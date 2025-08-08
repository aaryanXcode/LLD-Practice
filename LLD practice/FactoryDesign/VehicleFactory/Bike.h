#pragma once 
#include<iostream>
using namespace std;
class Bike:public Vehicle{
    public:
        void start() override{
            cout<<"starting bike"<<endl;
        }
};