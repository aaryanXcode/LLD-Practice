#include "Maruti.h"
#include "Honda.h"
#include <iostream>
using namespace std;
int main(){
    string brand, type, tier;
    cout << "Enter brand (maruti/honda): ";
    cin >> brand;
    cout << "Enter vehicle type (car/bike/truck): ";
    cin >> type;
    cout << "Enter tier (basic/luxury): ";
    cin >> tier;

    VehicleFactory* factory = nullptr;
    if (brand == "maruti") factory = new Maruti();
    else if (brand == "honda") factory = new Honda();

    if (!factory) {
        cout << "Invalid brand" << endl;
        return 1;
    }

    Vehicle* vehicle = nullptr;
    if (type == "car") {
        vehicle = (tier == "basic") ? factory->createBasicCar() : factory->createLuxuryCar();
    } else if (type == "bike") {
        vehicle = (tier == "basic") ? factory->createBasicBike() : factory->createLuxuryBike();
    } else if (type == "truck") {
        vehicle = (tier == "basic") ? factory->createBasicTruck() : factory->createLuxuryTruck();
    }

    if (!vehicle) {
        cout << "Invalid vehicle type or tier" << endl;
        delete factory;
        return 1;
    }

    vehicle->start();

    delete vehicle;
    delete factory;
    return 0;
}