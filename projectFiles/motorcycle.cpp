#include "motorcycle.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "vehicles.h"


void Motorcycle::addMotorcycleToVector(Vehicle& vehicle,std::vector<std::string>& motorcycleVector){
    Motorcycle motorcycle;
    std::string passengerSeat;
    std::string luggageSpace;
    std::string color;

    Vehicle::sendVehicleData(vehicle);

    std::cout << "Does this Bike have passenger seat(Passenger Seat/No Passenger): ";
    getline(std::cin, passengerSeat);

    std::cout << "Does this Bike have luggage space(Has Luggage/No Luggage): ";
    getline(std::cin, luggageSpace);

    std::cout << "Enter the color of the vehicle: ";
    getline(std::cin, color);

    std::stringstream motorcycleInfo;

    motorcycleInfo << vehicle.getType() << ":" << vehicle.getMake() << ":" << vehicle.getModel() << ":$" << vehicle.getPricePerDay()
                   << ":" << vehicle.getEngineSize() << "cc" << ":" << motorcycle.getPassengerSeat() << " seats" << ":" << motorcycle.getLuggageSpace() << " cubic meters luggage space"
                   << ":" << (new Vehicle)->getRegistrationNumber() << ":" << motorcycle.getColor() << ":" << vehicle.getAvailable() << ":" << vehicle.getDateAvailable();

    motorcycleVector.push_back(motorcycleInfo.str());

    std::cout << "\n---- MOTORCYCLE SUCCESSFULLY ADDED ----\n";
}
