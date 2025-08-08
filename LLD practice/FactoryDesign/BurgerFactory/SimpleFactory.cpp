#include<bits/stdc++.h>
#include "Prepare.h"
using namespace std;

class Burger:public Prepare{
    
};

class StandardBurger: public Burger{
    void prepare() override{
        cout<<"prepairing standard burger"<<endl;
    }
};

class BasicBurger: public Burger{
    void prepare() override{
        cout<<"prepairing basic burger"<<endl;
    }
};

class PremiumBurger: public Burger{
    void prepare() override{
        cout<<"prepairing Premium burger"<<endl;
    }
};

int main(){
    string type;
    cout<<"enter type of burger"<<endl;
    cin>>type;
    Burger* burger = NULL;
    if(type=="basic"){
        burger = new BasicBurger();
    }else if(type=="standard"){
        burger = new StandardBurger();
    }else if(type=="premium"){
        burger = new PremiumBurger();
    }
    burger->prepare();
    delete burger;
    return 0;
}