#ifndef CW1_VAN_H
#define CW1_VAN_H

#include <vector>
#include "vehicles.h"

class Van : public Vehicle {
private:
    std::string type = "Van";
    std::string luggageSpace;
    std::string color;

public:
    static void addVanTOVector(Vehicle& vehicle,std::vector<std::string>& vanVector);

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

#endif //CW1_VAN_H
