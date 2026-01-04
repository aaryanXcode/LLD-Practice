#ifndef PANEL_H
#define PANEL_H
#include <vector>
#include "Direction.h"
class Panel {
private:
    std::vector<Button*> buttons;

public:
    void addButton(Button* button) {
        buttons.push_back(button);
    }

    Request* pressFloorButton(int floor) {
        return new Request(floor, Direction::IDLE);
    }
};

#endif
