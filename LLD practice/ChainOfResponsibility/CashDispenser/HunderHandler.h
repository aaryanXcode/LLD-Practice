#pragma once
#include "IHandler.h"

class HunderHandler:public IHandler{
    int numNotes;
    public:
        HunderHandler(int count){
            this->numNotes = count;
        }

        void dispense(int amount) override{
            int notesNeeded = amount / 100;

            if(notesNeeded > numNotes) {
                notesNeeded = numNotes;
                numNotes = 0;
            }
            else {
                numNotes -= notesNeeded;
            }

            if(notesNeeded > 0)
                cout << "Dispensing " << notesNeeded << " x ₹100 notes.\n";

            int remainingAmount = amount - (notesNeeded * 100);
            if(remainingAmount > 0) {
                if(nextHandler != nullptr) nextHandler->dispense(remainingAmount);
                else {
                    cout << "Remaining amount of " << remainingAmount << " cannot be fulfilled (Insufficinet fund in ATM)\n";
                }
            }
        }
};