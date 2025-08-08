#pragma once
#include "Engine.h"
#include<bits/stdc++.h>
using namespace std;
class Petrol:public Engine{
    public:
        void start() override{
            cout<<"starting petrol engine"<<endl;
        }

};