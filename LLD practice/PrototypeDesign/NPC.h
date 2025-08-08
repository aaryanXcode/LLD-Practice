#pragma once
#include "Cloneable.h"
#include<bits/stdc++.h>
using namespace std;

class NPC:public Cloneable{
    public:
        string name;
        int health;
        int attack;
        int defence;

        NPC(const string& name,int health,int attack,int defense){

            this->name = name;
            this->health = health;
            this->attack = attack;
            this->defence = defense;
            
        }

        //copy constructor
        NPC(const NPC& other){
            name = other.name;
            health = other.health;
            attack = other.attack;
            defence = other.defence;
            cout << "Cloning NPC '" << name << "'\n";
        }

        Cloneable* clone() const override {
            return new NPC(*this);
        }

        void describe() {
            cout << "NPC " << name  << " [HP=" << health  << " ATK=" << attack 
                << " DEF=" << defence << "]\n";
        }

        void setName(const string& n) { 
            name = n;
        }
        void setHealth(int h) { 
            health = h;
        }
        void setAttack(int a) {
            attack = a; 
        }
        void setDefense(int d){ 
            defence = d;
        }

};

