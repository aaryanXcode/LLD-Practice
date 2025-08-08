#pragma once
#include "Burger.h"
#include "BasicBurger.h"
#include "BasicWheat.h"
#include "StandardBurger.h"
#include "StandardWheat.h"
#include "PremiumBurger.h"
#include "PremiumWheat.h"
class BurgerFactory{
    public:
        static Burger* createBurger(string type){
            if(type=="basic") return new BasicBurger();
            if(type=="standard") return new StandardBurger();
            if(type=="premium") return new PremiumBurger();
            if(type=="basicwheat") return new BasicWheatBurger();
            if(type=="standardwheat") return new StandardWheatBurger();
            if(type=="premiumwheat") return new PremiumWheatBurger();
            return NULL;
        }
};