#ifndef BUTTON_H
#define BUTTON_H

#include "ButtonType.h"
class Button {
private:
    ButtonType type;
    bool pressed;

public:
    Button(ButtonType type) : type(type), pressed(false) {}

    void press() {
        pressed = true;
    }

    ButtonType getType() const {
        return type;
    }

    bool isPressed() const {
        return pressed;
    }

    void reset() {
        pressed = false;
    }
};

#endif