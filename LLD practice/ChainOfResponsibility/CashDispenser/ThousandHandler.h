#pragma once
#include "IHandler.h"

class ThousandHandler:public IHandler{
    int numNotes;
    public:
        ThousandHandler(int count){
            this->numNotes = count;
        }

        void dispense(int amount) override{
            int notesNeeded = amount / 1000;

            if(notesNeeded > numNotes) {
                notesNeeded = numNotes;
                numNotes = 0;
            }
            else {
                numNotes -= notesNeeded;
            }

            if(notesNeeded > 0)
                cout << "Dispensing " << notesNeeded << " x ₹1000 notes.\n";

            int remainingAmount = amount - (notesNeeded * 1000);
            if(remainingAmount > 0) {
                if(nextHandler != nullptr) nextHandler->dispense(remainingAmount);
                else {
                    cout << "Remaining amount of " << remainingAmount << " cannot be fulfilled (Insufficinet fund in ATM)\n";
                }
            }
        }
};