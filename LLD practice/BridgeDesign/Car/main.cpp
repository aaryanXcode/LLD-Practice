#include "Car.h"
#include "Petrol.h"
#include "Desiel.h"
#include "EV.h"
#include "Sedan.h"
#include "XUV.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
    Engine* petrolEngine = new Petrol();
    Car* sedan = new Sedan(petrolEngine);
    sedan->drive();

    Engine* dieselEngine = new Desiel();
    Car* xuv = new XUV(dieselEngine);
    xuv->drive();

    Engine* evEngine = new EV();
    Car* evCar = new Sedan(evEngine);
    evCar->drive();

    delete petrolEngine;
    delete dieselEngine;
    delete evEngine;
    delete sedan;
    delete xuv;
    delete evCar;

    return 0;
}