#pragma once 
#include "Fan.h"
#include "ICommandRunner.h"
#include<bits/stdc++.h>
using namespace std;
class FanCommand:public ICommandRunner{
    Fan* fan;
    public:
        FanCommand(Fan* f){
            this->fan = f;
        }

        void execute() override{
            this->fan->on();
        }

        void undo() override{
            this->fan->off();
        }
};