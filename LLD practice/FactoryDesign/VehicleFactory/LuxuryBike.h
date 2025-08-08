#pragma once
#include<iostream>
using namespace std;
class LuxuryBike:public Vehicle{
    public:
        void start() override{
            cout<<"Starting luxuryBike"<<endl;
        }
};