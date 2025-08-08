#pragma once
#include "Channel.h"

class Subscriber:public ISubscriber{
    string name;
    Channel* channel;
    public:
        Subscriber(string name, Channel* ch) {
            this->name = name;
            this->channel = ch;
        }
        void update() override{
            cout<< this->name<<" "<<this->channel->getChannelName() <<" : has uploaded a new video->"<<this->channel->getlatestVideo()<<endl; 
        }
};