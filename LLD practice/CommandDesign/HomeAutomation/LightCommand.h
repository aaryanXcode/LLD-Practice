#pragma once 
#include "Light.h"

#include<bits/stdc++.h>
using namespace std;
class LightCommand: public ICommandRunner{
    Light* light;
    public:
        LightCommand(Light* l){
            this->light = l;
        }

        void execute() override{
            this->light->on();
        }

        void undo() override{
            this->light->off();
        }
};