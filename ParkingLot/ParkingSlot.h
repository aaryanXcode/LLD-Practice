class ParkingSlot {
private:
    int slotId;
    bool isOccupied;

public:
    // Getter for slotId
    int getSlotId() {
        return slotId;
    }
    
    // Setter for slotId
    void setSlotId(int slotId) {
        this->slotId = slotId;
    }
    
    // Getter for isOccupied
    bool getIsOccupied() {
        return isOccupied;
    }
    
    // Setter for isOccupied
    void setIsOccupied(bool isOccupied) {
        this->isOccupied = isOccupied;
    }

    bool operator>(const ParkingSlot& other) const {
        return slotId > other.slotId;
    }
};