#include "Walkable.h"
#include<bits/stdc++.h>
using namespace std;
class NormalWalk: public Walkable{
    public:
        void walk() override {
            cout<<"Robot can walk"<<endl;
        }

};