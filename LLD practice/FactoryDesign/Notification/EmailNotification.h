#pragma once
#include<bits/stdc++.h>
using namespace std;
#include "Notification.h"

class EmailNotification:public Notification{
    public:
        void notify() override{
            cout<<"Sending notification to Email"<<endl;
        }
};