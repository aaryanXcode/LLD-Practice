
#include "ICommandRunner.h"
#include "Remote.h"
#include "LightCommand.h"
#include "FanCommand.h"
#include<bits/stdc++.h>
using namespace std;

int main(){
    Remote* remote = new Remote();

    remote->setCommand(1,new LightCommand(new Light()));
    remote->setCommand(2,new FanCommand(new Fan()));
    remote->pressButton(1);
    remote->pressButton(2);
    remote->pressButton(1);
    remote->pressButton(2);
}