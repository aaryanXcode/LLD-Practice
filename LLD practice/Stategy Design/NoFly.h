#include "Flyable.h"
#include<bits/stdc++.h>
using namespace std;
class NoFly: public Flyable{
    public:
        void fly() override {
            cout<<"Robot can't fly"<<endl;
        }

};