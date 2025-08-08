#pragma once
#include "Cpu.h"
#include "Memory.h"
#include <bits/stdc++.h>
using namespace std;
class Bios {
public:
    void boot(Cpu& cpu, Memory& memory) {
        cout << "BIOS: Booting CPU and Memory checks..." << endl;
        cpu.startingCpu();
        memory.startingMemory();
    }
};