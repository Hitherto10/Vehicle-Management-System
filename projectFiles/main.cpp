/*
 main.cpp
 Student ID: M00804152
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "codeFunctions.h"
#include "vehicles.h"
#include "motorcycle.h"
#include "car.h"
#include "van.h"


std::vector<std::string> vehicleContainer;

void addVehicle(Vehicle& vehicle) {
    int vehicleChoice;
    std::string answer;

    while (true)  {
        while (true){
            std::cout << "\n\nWhat Type of vehicle do you want to add to the database?\n\n";
            std::cout << "1. Car\n" << "2. Van\n" << "3. Motorcycle\n\n";
            std::cin >> vehicleChoice;

            if (vehicleChoice == 1) {
                vehicle.setType("Car");
                Car::addCarToVector(vehicle, vehicleContainer);
                break;
            } else if (vehicleChoice == 2) {
                vehicle.setType("Van");
                Van::addVanTOVector(vehicle, vehicleContainer);
                break;
            } else if (vehicleChoice == 3) {
                vehicle.setType("Motorcycle");
                Motorcycle::addMotorcycleToVector(vehicle, vehicleContainer);
                break;
            } else{
                std::cout << "Input either 1, 2 or 3";
            }
        }

        std::cout << "\nDo you wish to add another vehicle (Yes/No)?: ";
        std::cin >> answer;
        if (answer == "No" || answer == "no"){
            break;
        }
    }
}


void saveVehicle(std::string& FILE_NAME) {
    std::ofstream outFile(FILE_NAME, std::ios::app);

    while (true)
    {
        if (vehicleContainer.empty() == 0)
        {
            for (std::string& s : vehicleContainer) {
                outFile << s << std::endl;
            }

            std::cout << "\n---- VEHICLE SUCCESSFULLY SAVED ----\n";
        }
        else
        {
            std::cout << "Error: Add Vehicles first\n";
        }
        break;
    }
    vehicleContainer.clear();
}

void removeVehicle(const std::string& FILE_NAME) {
    std::string registrationNumber;

    std::cout << "\nEnter the registration number for the car you want to delete: ";
    std::cin >> registrationNumber;

    std::ifstream fileToBeChanged(FILE_NAME);
    std::ofstream tempFile("temp.txt");

    // Read the file line by line
    std::string line;
    while (std::getline(fileToBeChanged, line)) {

        // If the line does not contain the word, write it to the temporary file
        if (line.find(registrationNumber) == std::string::npos) {
            tempFile << line << std::endl;
        }
    }

    // Close both files
    fileToBeChanged.close();
    tempFile.close();

    // Delete the original file
    std::remove(FILE_NAME.c_str());

    // Rename the temporary file to the original file
    std::rename("temp.txt", FILE_NAME.c_str());
    std::cout << "\n---- VEHICLE SUCCESSFULLY REMOVED ----\n";
}

void listVehicleDetails(const std::string& FILE_NAME){
    std::string word;
    int num = 0;

    std::ifstream MyReadFile(FILE_NAME);

    while (getline (MyReadFile, word)) {
        std::istringstream iss(word);

        std::string temporaryVariable, make, model, registrationNo, availability, dateAvailable;
        
        std::getline(iss, temporaryVariable, ':');
        std::getline(iss, make, ':');
        std::getline(iss, model, ':');

        for (int i = 0; i < 4; i++) {
            std::string temp;
            std::getline(iss, temp, ':');
        }

        std::getline(iss, registrationNo, ':');

        for (int i = 0; i < 1; i++) {
            std::string temp;
            std::getline(iss, temp, ':');
        }
        std::getline(iss, availability, ':');
        std::getline(iss, dateAvailable, ':');

        if (availability == "No" || availability == "no") {
            num++;
            std::cout << "Vehicle" << ' ' << num << '\n';
            std::cout << "Make: " << make << '\n';
            std::cout << "Model: " << model << '\n';
            std::cout << "Registration Number: " << registrationNo << '\n';
            std::cout << "Availability: " << availability << '\n';
            std::cout << "Date Available: " << dateAvailable << "\n\n";
        } else{
            num++;
            std::cout << "Vehicle" << ' ' << num << '\n';
            std::cout << "Make: " << make << '\n';
            std::cout << "Model: " << model << '\n';
            std::cout << "Registration Number: " << registrationNo << '\n';
            std::cout << "Availability: " << availability << "\n\n";
        }
    }

// Close the file
    MyReadFile.close();
}


void displayVehicleDetails(const std::string& FILE_NAME) {
    std::string registrationNumber;
    std::string line;
    std::string word;
    std::ifstream MyReadFile(FILE_NAME);

    std::cout << "\nEnter the registration number for the car you want to display : ";
    std::cin >> registrationNumber;
    while (std::getline(MyReadFile, line)) {
        // Check if the line contains the specific word
        if (line.find(registrationNumber) != std::string::npos) {
            std::istringstream iss(line);

            std::string type, make, model, pricePerDay, engineSize, passengerSeat, LuggageSpace, color,
                        numberOfSeats, numberOfDoors, registrationNo, availability, dateAvailable;

            std::getline(iss, type, ':');
            std::getline(iss, make, ':');
            std::getline(iss, model, ':');
            std::getline(iss, pricePerDay, ':');
            std::getline(iss, engineSize, ':');

            if (type == "bike" || type == "Bike") {
                std::getline(iss, passengerSeat, ':');
                std::getline(iss, LuggageSpace, ':');
            }else if (type == "car" || type == "Car") {
                std::getline(iss, numberOfSeats, ':');
                std::getline(iss, numberOfDoors, ':');
            }else if (type == "Van" || type == "van") {
                std::getline(iss, numberOfSeats, ':');
                std::getline(iss, LuggageSpace, ':');
            }

            std::getline(iss, registrationNo, ':');
            std::getline(iss, color, ':');
            std::getline(iss, availability, ':');
            std::getline(iss, dateAvailable, ':');

            std::cout << "\nMake: " << make << '\n';
            std::cout << "Model: " << model << '\n';
            std::cout << "Price Per Day: " << pricePerDay << '\n';
            std::cout << "Engine Size: " << engineSize << '\n';

            if (type == "bike" || type == "Bike"){
                std::cout << "Passenger Seat: " << passengerSeat << '\n';
                std::cout << "Luggage Space: " << LuggageSpace << '\n';
            } else if (type == "car" || type == "Car"){
                std::cout << "Number of Seats: " << numberOfSeats << '\n';
                std::cout << "Number of Doors: " << numberOfDoors << '\n';
            } else if (type == "van" || type == "Van"){
                std::cout << "Number of Seats: " << numberOfSeats << '\n';
                std::cout << "Luggage Space: " << LuggageSpace << '\n';
            }

            std::cout << "Registration Number: " << registrationNo << '\n';
            std::cout << "Color: " << color << '\n';
            std::cout << "Availability: " << availability << '\n';

            if (availability == "No" || availability == "no"){
                std::cout << "Date Available: " << dateAvailable << "\n\n";
            }
        }
    }
}

int main() {
    std::vector<std::string> vec;
    std::fstream file1;

    // Declare the file name as a string
    std::string fileName;

    while (true)
    {
        std::cout << "\n\nEnter the name of the file to be implemented: ";
        std::cin >> fileName;

        file1.open(fileName);
        if (file1.is_open())
        {
            break;
        }
        else
        {
            std::cout << "Error: File does not exist. Please try again.\n";
        }
    }

    // File was successfully opened and can now be read from
    std::cout << "File was successfully opened." << std::endl;


    Vehicle vehicle;


    while (true){
        std::cout << "\n\n----------------------------------------\n";
        std::cout << "        CAR MANAGEMENT SYSTEM\n";
        std::cout << "----------------------------------------\n\n";

        std::cout << "What operation do you want to carry out?\n\n";

        std::cout << "1. Add Vehicle\n";
        std::cout << "2. Save Vehicle to file\n";
        std::cout << "3. Remove Vehicle\n";
        std::cout << "4. List All Vehicles\n";
        std::cout << "5. Display Details of a Vehicle\n";
        std::cout << "0. Exit Software\n\n";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            addVehicle(vehicle);
        } else if (choice == 2) {
            saveVehicle(fileName);
        } else if (choice == 3) {
            removeVehicle(fileName);
        } else if (choice == 4) {
            listVehicleDetails(fileName);
        } else if (choice == 5) {
            displayVehicleDetails(fileName);
        } else if (choice == 0) {
            break;
        } else {
            std::cout << "Error: invalid operation number.\n";
        }
    }

    return 0;
}
