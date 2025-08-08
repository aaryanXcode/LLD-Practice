#pragma once
#include "VehicleFactory.h"
#include "Car.h"
#include "Bike.h"
#include "Truck.h"
#include "LuxuryCar.h"
#include "LuxuryBike.h"
#include "LuxuryTruck.h"
class Maruti:public VehicleFactory{
    public:
        Vehicle* createBasicCar() override { return new Car(); }
        Vehicle* createLuxuryCar() override { return new LuxuryCar(); }
        Vehicle* createBasicBike() override { return new Bike(); }
        Vehicle* createLuxuryBike() override { return new LuxuryBike(); }
        Vehicle* createBasicTruck() override { return new Truck(); }
        Vehicle* createLuxuryTruck() override { return new LuxuryTruck(); }
    
};
