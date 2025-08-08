#pragma once
#include<bits/stdc++.h>
#include "ICommandRunner.h"
using namespace std;
class Remote{
    static const int numButtons = 4;
    ICommandRunner* buttons[numButtons];
    bool buttonPressed[numButtons];
    public:
        Remote(){
            for (int i = 0; i < numButtons; i++) {
                buttons[i] = nullptr;
                buttonPressed[i] = false;  // false = off, true = on
            }
        }
        //set index to the command for fan or light
        void setCommand(int idx, ICommandRunner* cmd) {
            if (idx >= 0 && idx < numButtons) {
                if (buttons[idx] != nullptr)
                    delete buttons[idx];
                buttons[idx] = cmd;
                buttonPressed[idx] = false;
            }
        }

        void pressButton(int idx) {
            if (idx >= 0 && idx < numButtons && buttons[idx] != nullptr) {
                if (buttonPressed[idx] == false) {
                    buttons[idx]->execute();
                } else {
                    buttons[idx]->undo();
                }
                buttonPressed[idx] = !buttonPressed[idx];
            } else {
                cout << "No command assigned at button " << idx << endl;
            }
        }

    
};