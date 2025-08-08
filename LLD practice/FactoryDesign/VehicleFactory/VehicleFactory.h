#pragma once
#include<bits/stdc++.h>
#include "Vehicle.h"
class VehicleFactory{
    public:
        virtual Vehicle* createBasicCar() = 0;
        virtual Vehicle* createLuxuryCar() = 0;
        virtual Vehicle* createBasicBike() = 0;
        virtual Vehicle* createLuxuryBike() = 0;
        virtual Vehicle* createBasicTruck() = 0;
        virtual Vehicle* createLuxuryTruck() = 0;
        virtual ~VehicleFactory() {}
};