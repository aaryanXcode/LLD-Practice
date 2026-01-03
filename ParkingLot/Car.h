#ifndef CAR_H
#define CAR_H

#include <string>
#include "Color.h"
using namespace std;

class Car {
private:
    string registrationNumber;
    Color color;

public:
    void setColor(Color color) {
        this->color = color;
    }
    
    void setRegistrationNumber(string rgn) {
        this->registrationNumber = rgn;
    }
    
    Color getColor() {
        return this->color;
    }
    
    string getRegistrationNumber() {
        return this->registrationNumber;
    }
};

#endif