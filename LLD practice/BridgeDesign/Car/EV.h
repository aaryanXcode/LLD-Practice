#pragma once
#include "Engine.h"
#include<bits/stdc++.h>
using namespace std;
class EV:public Engine{
    public:
        void start() override{
            cout<<"starting EV engine"<<endl;
        }

};