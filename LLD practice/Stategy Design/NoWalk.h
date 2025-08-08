#include "Walkable.h"
#include<bits/stdc++.h>
using namespace std;
class NoWalk: public Walkable{
    public:
        void walk() override {
            cout<<"Robot can't walk"<<endl;
        }

};