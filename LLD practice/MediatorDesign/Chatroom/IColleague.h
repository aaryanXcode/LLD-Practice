#pragma once
#include<bits/stdc++.h>
#include "IMediator.h"
using namespace std;
class IColleague{
    protected:
        IMediator* mediator;
    public:
        virtual string getName() = 0;
        virtual void send(const string& msg) = 0;
        virtual void sendPrivate(const string& to, const string& msg) = 0;
        virtual void receive(const string& from, const string& msg) = 0;
};