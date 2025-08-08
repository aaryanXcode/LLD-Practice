#pragma once
#include "VehicleFactory.h"
#include "Bike.h"
#include "Car.h"
#include "Truck.h"
#include "LuxuryBike.h"
#include "LuxuryCar.h"
#include "LuxuryTruck.h"
class Honda:public VehicleFactory{
    public:
        Vehicle* createBasicCar() override { return new Car(); }
        Vehicle* createLuxuryCar() override { return new LuxuryCar(); }
        Vehicle* createBasicBike() override { return new Bike(); }
        Vehicle* createLuxuryBike() override { return new LuxuryBike(); }
        Vehicle* createBasicTruck() override { return new Truck(); }
        Vehicle* createLuxuryTruck() override { return new LuxuryTruck(); }
    
};
