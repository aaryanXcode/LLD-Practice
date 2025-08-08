#include "Flyable.h"
#include<bits/stdc++.h>
using namespace std;
class NormalFly: public Flyable{
    public:
        void fly() override {
            cout<<"Robot can fly"<<endl;
        }

};