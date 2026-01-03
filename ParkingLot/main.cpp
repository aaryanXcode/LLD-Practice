#include <iostream>
#include "ParkingLot.h"
#include "Car.h"
#include "Ticket.h"
using namespace std;

int main() {
    // Create parking lot
    ParkingLot parkingLot;
    
    // Create cars
    Car* car1 = new Car();
    car1->setRegistrationNumber("ABC123");
    car1->setColor(RED);
    
    Car* car2 = new Car();
    car2->setRegistrationNumber("XYZ789");
    car2->setColor(WHITE);
    
    Car* car3 = new Car();
    car3->setRegistrationNumber("DEF456");
    car3->setColor(RED);
    
    // Park cars
    cout << "=== Parking Cars ===" << endl;
    Ticket* ticket1 = parkingLot.park(car1);
    Ticket* ticket2 = parkingLot.park(car2);
    Ticket* ticket3 = parkingLot.park(car3);
    
    cout << "\n=== Finding Parking Slot ===" << endl;
    ParkingSlot* slot = parkingLot.getParkingSlotByRegistrationNumber("ABC123");
    if (slot != nullptr) {
        cout << "Car ABC123 is at slot: " << slot->getSlotId() << endl;
    }
    
    cout << "\n=== Getting RED cars ===" << endl;
    list<ParkingSlot*> redCarSlots = parkingLot.getParkingSlotsByColor(RED);
    cout << "Number of RED cars parked: " << redCarSlots.size() << endl;
    for (auto slot : redCarSlots) {
        cout << "RED car at slot: " << slot->getSlotId() << endl;
    }
    
    // Unpark a car
    cout << "\n=== Unparking Car ===" << endl;
    parkingLot.unPark(ticket1);
    
    // Clean up
    delete car1;
    delete car2;
    delete car3;
    delete ticket1;
    delete ticket2;
    delete ticket3;
    
    return 0;
}