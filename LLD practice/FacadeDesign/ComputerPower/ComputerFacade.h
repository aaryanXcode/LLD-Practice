#pragma once
#include "CoolingSystem.h"
#include "Cpu.h"
#include "Memory.h"
#include "Harddrive.h"
#include "Bios.h"
#include<bits/stdc++.h>
using namespace std;
class ComputerFacade {
    private:
        
        CoolingSystem coolingSystem;
        Cpu cpu;
        Memory memory;
        Harddrive hardDrive;
        Bios bios;
       
    public:
        void startComputer() {
            cout << "----- Starting Computer -----" << endl;
            
            coolingSystem.startingCoolingSystem();
            bios.boot(cpu, memory);
            hardDrive.startingHarddrive();
            cout << "Computer Booted Successfully!" << endl;
    }
};