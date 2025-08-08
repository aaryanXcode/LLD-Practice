#pragma once
#include "Car.h"
#include<bits/stdc++.h>
using namespace std;
class XUV:public Car{
    public:
        XUV(Engine* e):Car(e){

        }
        void drive() override{
            cout<<"driving XUV with Engine"<<endl;
            engine->start();
            cout<<endl;
        }
};