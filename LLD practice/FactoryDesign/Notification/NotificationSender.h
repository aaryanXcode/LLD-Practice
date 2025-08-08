#pragma once

//behaviour
class TwilioNotificationSender{
    public:
        virtual void send()=0;
        virtual ~TwilioNotificationSender(){};
};