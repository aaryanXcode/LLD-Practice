#include "Talkable.h"
#include<bits/stdc++.h>
using namespace std;
class NoTalk: public Talkable{
    public:
        void talk() override {
            cout<<"Robot can't talk"<<endl;
        }

};