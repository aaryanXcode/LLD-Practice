#pragma once
#include "Engine.h"
class Car{
    protected:
        Engine* engine;
    public:
        Car(Engine* e){
            this->engine = e;
        }
        virtual void drive() =0 ;
        virtual ~Car(){}
};