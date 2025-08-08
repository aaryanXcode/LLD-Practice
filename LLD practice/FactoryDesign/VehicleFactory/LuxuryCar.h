#pragma once
#include<iostream>
using namespace std;
class LuxuryCar:public Vehicle{
    public:
        void start() override{
            cout<<"starting luxury car"<<endl;
        }
};