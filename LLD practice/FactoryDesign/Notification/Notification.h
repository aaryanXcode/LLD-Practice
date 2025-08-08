#pragma once
class Notification{
    //set properties which should be found in each basic notification object
    public:
        virtual void notify() = 0;
        virtual ~Notification(){};
};