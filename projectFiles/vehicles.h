#ifndef CW_CHANGES_VEHICLE_H
#define CW_CHANGES_VEHICLE_H

#include <iostream>
#include <fstream>
#include <string>
#include "codeFunctions.h"

class Vehicle {
private:
    std::string type, make, model, registrationNumber = generateRegNum(), available, dateAvailable;
    double pricePerDay, engineSize, numberOfSeats;


public:
    static void sendVehicleData(Vehicle& vehicle);

    // Initiate Setter functions for Member Variables of Class Vehicle using template
    template <typename TEMPLATE>
    void setValue(TEMPLATE& memberVariable, const TEMPLATE& value) {
        memberVariable = value;
    }

    void setType(const std::string& type) {
        setValue(this->type, type);
    }


    void setMake(std::string make) {
        setValue(this->make, make);
    }


    void setModel(std::string model) {
        setValue(this->model, model) ;
    }


    void setPricePerDay(double pricePerDay) {
        setValue(this->pricePerDay, pricePerDay);
    }


    void setEngineSize(double engineSize) {
        setValue(this->engineSize, engineSize);
    }


    void setNumberOfSeats(double numberOfSeats) {
        setValue(this->numberOfSeats, numberOfSeats);
    }


    void setRegistrationNumber(std::string registrationNumber) {
        setValue(this->registrationNumber, registrationNumber);
    }


    void setAvailable(std::string available) {
        setValue(this->available, available);
    }


    void setDateAvailable(std::string dateAvailable) {
        setValue(this->dateAvailable, dateAvailable) ;
    }


    // Initiate getter functions for Member Variables of Class Vehicle using template
    template <typename TEMPLATE>
    TEMPLATE getValue(const TEMPLATE& memberVariable) {
        return memberVariable;
    }

    std::string getType(){
        return getValue(type);
    }

    std::string getMake(){
        return getValue(make);
    }

    std::string getModel(){
        return getValue(model);
    }

    double getPricePerDay(){
        return getValue(pricePerDay);
    }

    double getEngineSize(){
        return getValue(engineSize);
    }

    double getNumberOfSeats(){
        return getValue(numberOfSeats);
    }

    std::string getRegistrationNumber(){
        return getValue(registrationNumber);
    }

    std::string getAvailable(){
        return getValue(available);
    }

    std::string getDateAvailable(){
        return getValue(dateAvailable);
    }


};


#endif
