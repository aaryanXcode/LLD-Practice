#pragma once
#include<bits/stdc++.h>
using namespace std;
class IHandler{
    protected:
        IHandler* nextHandler;
    public:
        IHandler(){
            this->nextHandler = nullptr;
        }
        void setNextHandle(IHandler* h) {
            this->nextHandler = h;
        }
        virtual void dispense(int amount) = 0;
        virtual ~IHandler(){}
};