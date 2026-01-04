#ifndef DOOR_H
#define DOOR_H

#include "DoorState.h"
class Door {
private:
    DoorState state;

public:
    Door() : state(DoorState::CLOSED) {}

    void open() {
        state = DoorState::OPEN;
    }

    void close() {
        state = DoorState::CLOSED;
    }

    DoorState getState() const {
        return state;
    }
};

#endif
