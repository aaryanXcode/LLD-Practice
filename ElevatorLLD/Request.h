#ifndef REQUEST_H
#define REQUEST_H
#include "Direction.h"
class Request {
public:
    int floor;
    Direction direction;

    Request(int floor, Direction direction) : floor(floor), direction(direction) {}
};

#endif
