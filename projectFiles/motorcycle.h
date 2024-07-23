#ifndef CW_CHANGES_MOTORCYCLE_H
#define CW_CHANGES_MOTORCYCLE_H

#include <vector>
#include "vehicles.h"

class Motorcycle : public Vehicle {
private:
    std::string type = "Motorcycle";
    std::string passengerSeat;
    std::string luggageSpace;
    std::string color;

public:
    static void addMotorcycleToVector(Vehicle& vehicle,std::vector<std::string>& vec);

    void setPassengerSeat(std::string passengerSeat){
        this->passengerSeat = passengerSeat;
    } std::string getPassengerSeat(){
        return passengerSeat;
    }

    void setLuggageSpace(std::string luggageSpace){
        this->luggageSpace = luggageSpace;
    } std::string getLuggageSpace(){
        return luggageSpace;
    }

    void setColor(std::string color){
        this->color = color;
    } std::string getColor(){
        return color;
    }
};



#endif
