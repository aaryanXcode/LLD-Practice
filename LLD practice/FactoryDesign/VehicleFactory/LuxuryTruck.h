#pragma once
#include<iostream>
using namespace std;
class LuxuryTruck:public Vehicle{
    public:
        void start() override{
            cout<<"creating luxury truck"<<endl;
        }
};