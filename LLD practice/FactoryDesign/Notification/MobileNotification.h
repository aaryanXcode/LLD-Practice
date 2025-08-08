#pragma once
#include<bits/stdc++.h>
using namespace std;
#include "Notification.h"

class MobileNotification:public Notification{
    public:
        void notify() override{
            cout<<"Sending notification to mobile"<<endl;
        }
};