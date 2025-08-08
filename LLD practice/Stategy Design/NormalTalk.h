#include "Talkable.h"
#include<bits/stdc++.h>
using namespace std;
class NormalTalk: public Talkable{
    public:
        void talk() override {
            cout<<"Robot can talk"<<endl;
        }

};