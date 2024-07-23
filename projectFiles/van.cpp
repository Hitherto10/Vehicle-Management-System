#include "van.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "vehicles.h"


void Van::addVanTOVector(Vehicle& vehicle,std::vector<std::string>& vanVector){
    Van van;
    std::string luggageSpace;
    std::string color;


    Vehicle::sendVehicleData(vehicle);

    std::cin.clear();
    std::cout << "Enter the luggage space of the vehicle (in cubic centimeters): ";
    getline(std::cin, luggageSpace);
    van.setLuggageSpace(luggageSpace);

    std::cout << "Enter the color of the vehicle: ";
    getline(std::cin, color);
    van.setColor(color);


    std::stringstream vanInfo;

    vanInfo << vehicle.getType() << ":" << vehicle.getMake() << ":" << vehicle.getModel() << ":$" << vehicle.getPricePerDay()
            << ":" << vehicle.getEngineSize() << "l" << ":" << vehicle.getNumberOfSeats() << " seats" << ":" << van.getLuggageSpace() << " cubic meters luggage space"
            << ":" << (new Vehicle)->getRegistrationNumber() << ":" << van.getColor() << ":" << vehicle.getAvailable() << ":" << vehicle.getDateAvailable();

    vanVector.push_back(vanInfo.str());

    std::cout << "\n---- VAN SUCCESSFULLY ADDED ----\n";


}
