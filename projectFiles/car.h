#ifndef CW1_CAR_H
#define CW1_CAR_H

#include <vector>
#include "vehicles.h"

class Car : public Vehicle {
private:
    std::string type = "Car";
    std::string numberOfDoors;
    std::string color;
public:

    static void addCarToVector(Vehicle& vehicle,std::vector<std::string>& vec);

    void setNumberOfDoors(std::string numberOfDoors){
        this->numberOfDoors = numberOfDoors;
    } std::string getNumberOfDoors(){
        return numberOfDoors;
    }

    void setColor(std::string color){
        this->color = color;
    } std::string getColor(){
        return color;
    }
};

#endif
