#pragma once
#include "ComputerFacade.h"
class Computer{
    ComputerFacade* computerFacade;
    public:
        Computer(ComputerFacade* comp){
            this->computerFacade = comp;
        }
        void execute(){
            this->computerFacade->startComputer();
        }
};