#include<bits/stdc++.h>
#include "Channel.h"
#include "Subscriber.h"
using namespace std;

int main(){
    Channel* channel = new Channel("System design channel","observerDesgin pattern");
    Subscriber* subscriber = new Subscriber("aryan(subscriber)",channel);
   
    channel->subscribe(subscriber);
    channel->notify();
    channel->unsubscribe(subscriber);
    channel->notify();
    channel->uploadVideo("facade design");
    
}