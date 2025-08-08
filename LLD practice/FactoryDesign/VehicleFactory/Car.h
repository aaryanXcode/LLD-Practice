#pragma once
#include<iostream>
using namespace std;
class Car:public Vehicle{
    public:
        void start() override{
            cout<<"starting car"<<endl;
        }
};