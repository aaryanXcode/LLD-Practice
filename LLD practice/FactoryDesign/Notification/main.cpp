
#include<bits/stdc++.h>
#include "NotificationSenderFactory.h"
using namespace std;

int main(){
    string type;
    cout << "Enter type of notification (mobile/email/whatsapp): ";
    cin >> type;
    Notification* notification = NotificationSenderFactory::sendNotification(type);
    if(notification==nullptr){
        cout<<"Please enter valid notification type";
        return 1;
    }
    notification->notify();
    return 0;
}