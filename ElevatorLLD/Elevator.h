#ifndef ELEVATOR_H
#define ELEVATOR_H
#include "Direction.h"
#include "ElevatorStatus.h"
class Elevator {
private:
    Display* display;
    Door* door;
    Panel* panel;
    int currentFloor;
    Direction direction;
    ElevatorStatus status;

public:
    Elevator(Display* d, Door* dr, Panel* p)
        : display(d), door(dr), panel(p),
          currentFloor(0),
          direction(Direction::IDLE),
          status(ElevatorStatus::STOPPED) {}

    void moveUp(int targetFloor) {
        direction = Direction::UP;
        status = ElevatorStatus::MOVING;
        std::cout << "[Elevator] Moving UP\n";
        while (currentFloor < targetFloor) {
            currentFloor++;
            display->update(currentFloor, direction);
        }
        stop();
    }

    void moveDown(int targetFloor) {
        direction = Direction::DOWN;
        status = ElevatorStatus::MOVING;

        std::cout << "[Elevator] Moving DOWN\n";
        while (currentFloor > targetFloor) {
            currentFloor--;
            display->update(currentFloor, direction);
        }
        stop();
    }

    void stop() {
        status = ElevatorStatus::STOPPED;
        direction = Direction::IDLE;
        std::cout << "[Elevator] Stopped at floor " << currentFloor << std::endl;
        door->open();
        door->close();
    }

    int getCurrentFloor() const {
        return currentFloor;
    }
};


#endif