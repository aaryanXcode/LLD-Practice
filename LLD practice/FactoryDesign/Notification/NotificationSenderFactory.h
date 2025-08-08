#pragma once
#include "Notification.h"
#include "MobileNotification.h"
#include "EmailNotification.h"
class NotificationSenderFactory{
    public:
        static Notification* sendNotification(string type){
            if(type=="mobile") return new MobileNotification();
            if(type=="email") return new EmailNotification();
            return nullptr;
        }
};