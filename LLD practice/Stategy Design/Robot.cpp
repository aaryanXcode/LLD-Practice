#include "Talkable.h"
#include "Walkable.h"
#include "Flyable.h"
#include "NormalWalk.h"
#include "NoWalk.h"
#include "NormalTalk.h"
#include "NoTalk.h"
#include "NormalFly.h"
#include "NoFly.h"
#include<bits/stdc++.h>
using namespace std;
class Robot{
    protected:
        Talkable* talkable;
        Flyable* flyable;
        Walkable* walkable;
    public:
        Robot(Talkable* t,Walkable* w,Flyable* f){
            this->talkable = t;
            this->walkable = w;
            this->flyable = f;
        }

        void walk(){
            walkable->walk();
        }

        void talk(){
            talkable->talk();
        }

        void fly(){
            flyable->fly();
        }

        virtual void projection() = 0;
};

class Companion :public Robot{
    public:
        Companion(Talkable* t,Walkable *w, Flyable* f):Robot(t,w,f){
        }

        void projection() override {
            cout << "Displaying worker efficiency stats... companion" << endl;
        }
};

int main(){
    Robot* robot = new Companion(new NormalTalk(), new NormalWalk(), new NoFly() );
    robot->walk();
    robot->talk();
    robot->fly();

    return 0;
}