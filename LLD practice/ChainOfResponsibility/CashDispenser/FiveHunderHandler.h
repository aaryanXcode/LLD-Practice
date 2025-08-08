#pragma once
#include "IHandler.h"

class FiveHunderHandler:public IHandler{
    int numNotes;
    public:
        FiveHunderHandler(int count){
            this->numNotes = count;
        }

        void dispense(int amount) override{
            int notesNeeded = amount / 500;

            if(notesNeeded > numNotes) {
                notesNeeded = numNotes;
                numNotes = 0;
            }
            else {
                numNotes -= notesNeeded;
            }

            if(notesNeeded > 0)
                cout << "Dispensing " << notesNeeded << " x ₹500 notes.\n";

            int remainingAmount = amount - (notesNeeded * 500);
            if(remainingAmount > 0) {
                if(nextHandler != nullptr) nextHandler->dispense(remainingAmount);
                else {
                    cout << "Remaining amount of " << remainingAmount << " cannot be fulfilled (Insufficinet fund in ATM)\n";
                }
            }
        }
};