#pragma once
#include "IHandler.h"

class TwoHunderHandler:public IHandler{
    int numNotes;
    public:
        TwoHunderHandler(int count){
            this->numNotes = count;
        }

        void dispense(int amount) override{
            int notesNeeded = amount / 200;

            if(notesNeeded > numNotes) {
                notesNeeded = numNotes;
                numNotes = 0;
            }
            else {
                numNotes -= notesNeeded;
            }

            if(notesNeeded > 0)
                cout << "Dispensing " << notesNeeded << " x ₹200 notes.\n";

            int remainingAmount = amount - (notesNeeded * 200);
            if(remainingAmount > 0) {
                if(nextHandler != nullptr) nextHandler->dispense(remainingAmount);
                else {
                    cout << "Remaining amount of " << remainingAmount << " cannot be fulfilled (Insufficinet fund in ATM)\n";
                }
            }
        }
};