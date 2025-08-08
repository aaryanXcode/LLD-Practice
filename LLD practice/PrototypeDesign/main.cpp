#include "NPC.h"

int main(){

    NPC* alien = new NPC("Alien", 3, 5, 2);

    //cloning and tweaking the existing object instead of creating object from the beginning
    NPC* newAlien = dynamic_cast<NPC*>(alien->clone());
    newAlien->describe();

    NPC* powerfullAlien = dynamic_cast<NPC*>(alien->clone());
    powerfullAlien->setName("powerfull alien");
    powerfullAlien->setAttack(50);
    powerfullAlien->describe();

    delete alien;
    delete newAlien;
    delete powerfullAlien;
    return 0;

}