#pragma once
#include "Car.h"
#include<bits/stdc++.h>
using namespace std;
class Sedan:public Car{
    public:
        Sedan(Engine* e):Car(e){

        }
        void drive() override{
            cout<<"driving sedan with Engine"<<endl;
            engine->start();
            cout<<endl;
        }
};