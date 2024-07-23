#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "vehicles.h"
#include "codeFunctions.h"


std::string type, vehicleMake, vehicleModel, vehicleAvailable, vehicleDateAvailable;
double vehiclePricePerDay, vehicleEngineSize, vehicleNumberOfSeats;

void Vehicle::sendVehicleData(Vehicle& vehicle){

    std::cin.ignore();
    std::cout << "\nEnter the make of the vehicle: ";
    getline(std::cin, vehicleMake);
    vehicle.setMake(vehicleMake);

    std::cout << "Enter the model of the vehicle: ";
    getline(std::cin, vehicleModel);
    vehicle.setModel(vehicleModel);


    while (true)
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "\bEnter the price per day to rent the vehicle: $";
        std::cin >> vehiclePricePerDay;


        if (vehiclePricePerDay)
        {
            break;
        }
        else
        {
            std::cout << "Error: Invalid input. Please try again.\n\n";
        }
    }

//    while (true)
//    {
//        std::cout << "Enter the price per day to rent the vehicle: $";
//        std::cin >> vehiclePricePerDay;
//
//        if (!checkVariableType(std::to_string(vehiclePricePerDay))) {
//            std::cout << "\nError: Invalid input. Please try again.\n\n";
//        }
//        else {
//            break;
//        }
//    }

    while (true)
    {
        if (vehicle.getType() == "Bike") {
            std::cout << "Enter the engine size of the bike (in cubic centimeters): ";
            std::cin >> vehicleEngineSize;
            vehicle.setEngineSize(vehicleEngineSize);
        } else {
            std::cout << "Enter the engine size of the vehicle (in liters): ";
            std::cin >> vehicleEngineSize;
            vehicle.setEngineSize(vehicleEngineSize);
        }

        // If the file was successfully opened, break out of the loop
        if (!(vehicleEngineSize))
        {
            std::cout << "Error: Enter a valid size\n\n";
        }
        else
        {
            break;
        }
    }

    if (vehicle.getType() != "Bike") {
        std::cin.ignore();
        std::cout << "Enter the number of seats in the vehicle: ";
        std::cin >> vehicleNumberOfSeats;
        vehicle.setNumberOfSeats(vehicleNumberOfSeats);
    }

    std::cout << "Enter the availability of the vehicle (Yes/No): ";
    std::cin >> vehicleAvailable;
    vehicle.setAvailable(vehicleAvailable);
    std::cin.clear();
    std::cin.ignore();

    if ( vehicle.getAvailable() == "No" ||  vehicle.getAvailable() == "no"){
        std::cout << "Enter the date the vehicle will be available (dd/mm/yyyy): ";
        getline(std::cin, vehicleDateAvailable);
        vehicle.setDateAvailable(vehicleDateAvailable);
    }
    else{
        vehicle.setDateAvailable("N/A");
    }

}

