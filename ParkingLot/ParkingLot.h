#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <queue>
#include <unordered_map>
#include <set>
#include <list>
#include <vector>
#include <iostream>
#include "Car.h"
#include "ParkingSlot.h"
#include "Ticket.h"
#include "Color.h"

using namespace std;

class ParkingLot {
private:
    priority_queue<ParkingSlot, vector<ParkingSlot>, greater<ParkingSlot>> availableSlots;
    unordered_map<string, ParkingSlot*> carToSlotMap;
    unordered_map<Color, set<ParkingSlot*>> slotsByColor;
    unordered_map<Color, list<Ticket*>> ticketsByColor;
    unordered_map<string, Ticket*> activeTickets;
    int ticketCounter;

public:
    ParkingLot() : ticketCounter(0) {
        // Initialize parking slots
        for (int i = 1; i <= 100; i++) {
            ParkingSlot slot;
            slot.setSlotId(i);
            slot.setIsOccupied(false);
            availableSlots.push(slot);
        }
    }
    
    Ticket* park(Car* car) {
        if (availableSlots.empty()) {
            cout << "No available parking slots!" << endl;
            return nullptr;
        }
        
        // Get the slot with smallest ID
        ParkingSlot slot = availableSlots.top();
        availableSlots.pop();
        slot.setIsOccupied(true);
        
        // Create ticket
        Ticket* ticket = new Ticket();
        ticket->setTicketId(++ticketCounter);
        ticket->setRegistrationNumber(car->getRegistrationNumber());
        ticket->setDate("2026-01-04");
        ticket->setPrice(10);
        ticket->setDuration(0);
        
        // Store mappings
        carToSlotMap[car->getRegistrationNumber()] = new ParkingSlot(slot);
        slotsByColor[car->getColor()].insert(carToSlotMap[car->getRegistrationNumber()]);
        ticketsByColor[car->getColor()].push_back(ticket);
        activeTickets[car->getRegistrationNumber()] = ticket;
        
        cout << "Car " << car->getRegistrationNumber() << " parked at slot: " << slot.getSlotId() << endl;
        return ticket;
    }
    
    void unPark(Ticket* ticket) {
        string regNum = ticket->getRegistrationNumber();
        
        if (carToSlotMap.find(regNum) == carToSlotMap.end()) {
            cout << "Car not found!" << endl;
            return;
        }
        
        ParkingSlot* slot = carToSlotMap[regNum];
        slot->setIsOccupied(false);
        
        // Add slot back to available slots
        availableSlots.push(*slot);
        
        // Clean up mappings
        carToSlotMap.erase(regNum);
        activeTickets.erase(regNum);
        
        cout << "Car " << regNum << " unparked from slot: " << slot->getSlotId() << endl;
        
        delete slot;
    }
    
    ParkingSlot* getParkingSlotByRegistrationNumber(string registrationNumber) {
        if (carToSlotMap.find(registrationNumber) != carToSlotMap.end()) {
            return carToSlotMap[registrationNumber];
        }
        return nullptr;
    }
    
    list<ParkingSlot*> getParkingSlotsByColor(Color color) {
        list<ParkingSlot*> result;
        if (slotsByColor.find(color) != slotsByColor.end()) {
            for (auto slot : slotsByColor[color]) {
                result.push_back(slot);
            }
        }
        return result;
    }
    
    list<Ticket*> getTicketsByColor(Color color) {
        if (ticketsByColor.find(color) != ticketsByColor.end()) {
            return ticketsByColor[color];
        }
        return list<Ticket*>();
    }
};

#endif