#include "car.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "vehicles.h"


void Car::addCarToVector(Vehicle& vehicle,std::vector<std::string>& carVector){
    Car car;
    std::string numberOfDoors;
    std::string color;

    Vehicle::sendVehicleData(vehicle);

    std::cin.clear();
    std::cout << "Enter the number of doors in the vehicle: ";
    getline(std::cin, numberOfDoors);
    car.setNumberOfDoors(numberOfDoors);

    std::cout << "Enter the color of the vehicle: ";
    getline(std::cin, color);
    car.setColor(color);

    std::stringstream carInfo;

    carInfo << vehicle.getType() << ":" << vehicle.getMake() << ":" << vehicle.getModel() << ":$" << vehicle.getPricePerDay()
            << ":" << vehicle.getEngineSize() << "cc" << ":" << vehicle.getNumberOfSeats() << " seats" << ":" << car.getNumberOfDoors() << " doors"
            << ":" << (new Vehicle)->getRegistrationNumber() << ":" << car.getColor() << ":" << vehicle.getAvailable() << ":" << vehicle.getDateAvailable();

    carVector.push_back(carInfo.str());

    std::cout << "\n---- CAR SUCCESSFULLY ADDED ----\n";
}
