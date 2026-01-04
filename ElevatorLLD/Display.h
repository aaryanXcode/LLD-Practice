#ifndef DISPLAY_H
#define DISPLAY_H

class Display {
private:
    int currentFloor;
    Direction direction;

public:
    void show() {
        // print or render floor + direction
    }

    void update(int floor, Direction direction) {
        std::cout << "[Display] Floor: " << floor << " Direction: ";
        if (direction == Direction::UP) std::cout << "UP\n";
        else if (direction == Direction::DOWN) std::cout << "DOWN\n";
        else std::cout << "IDLE\n";
    }
};

#endif
