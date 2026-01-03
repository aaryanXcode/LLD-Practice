#ifndef TICKET_H
#define TICKET_H

#include <string>
using namespace std;

class Ticket {
private:
    int ticketId;
    string registrationNumber;
    string date;
    int price;
    int duration;

public:
    int getTicketId() {
        return ticketId;
    }
    
    void setTicketId(int ticketId) {
        this->ticketId = ticketId;
    }
    
    string getRegistrationNumber() {
        return registrationNumber;
    }
    
    void setRegistrationNumber(string registrationNumber) {
        this->registrationNumber = registrationNumber;
    }
    
    string getDate() {
        return date;
    }
    
    void setDate(string date) {
        this->date = date;
    }
    
    int getPrice() {
        return price;
    }
    
    void setPrice(int price) {
        this->price = price;
    }
    
    int getDuration() {
        return duration;
    }
    
    void setDuration(int duration) {
        this->duration = duration;
    }
};

#endif