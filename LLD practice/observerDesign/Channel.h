#pragma once
#include<bits/stdc++.h>
#include "IChannel.h"
using namespace std;
class Channel:public IChannel{
    string channelName;
    vector<ISubscriber*> subscribers;
    string latestVideo;
    public:
        Channel(string name, string title){
            this->channelName = name;
            this->latestVideo = title;
        }
        void subscribe(ISubscriber* subscriber) override{
            if(find(subscribers.begin(),subscribers.end(),subscriber)==subscribers.end()){
                subscribers.push_back(subscriber);
            }
        }

        void unsubscribe(ISubscriber* subscriber) override {
            auto it = find(subscribers.begin(), subscribers.end(), subscriber);
            if (it != subscribers.end()) {
                subscribers.erase(it);  // Correct use
            }
        }

        void notify() override {
            for (ISubscriber* sub : subscribers) {
                sub->update();
            }
        }

        void uploadVideo(string title){
            this->latestVideo = title;
            notify();
        }

        string getChannelName(){
            return this->channelName;
        }

        string getlatestVideo(){
            return this->latestVideo;
        }

        
};