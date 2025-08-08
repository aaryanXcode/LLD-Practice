#pragma once
#include "IColleague.h"
class User:public IColleague{
    IMediator* mediator;
    string name;
    public:
        User(const std::string& name, IMediator* mediator) {
        this->name = name;
        this->mediator = mediator;
        mediator->registerColleague(this);
    }

    std::string getName() override {
        return name;
    }

    void send(const std::string& msg) override {
        std::cout << "[" << name << " sends to ALL]: " << msg << std::endl;
        mediator->send(name, msg);
    }

    void sendPrivate(const std::string& to, const std::string& msg) override {
        std::cout << "[" << name << " sends to " << to << "]: " << msg << std::endl;
        mediator->sendPrivate(name, to, msg);
    }

    void receive(const std::string& from, const std::string& msg) override {
        std::cout << "[" << name << " receives from " << from << "]: " << msg << std::endl;
    }

};