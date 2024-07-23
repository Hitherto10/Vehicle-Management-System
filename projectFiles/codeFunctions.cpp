#include <iostream>
#include <string>
#include <random>
#include <cstring>
#include <sstream>
#include "CodeFunctions.h"


// Function to generate random registration numbers3
std::string generateRegNum()
{
    std::string randomString;
    // Create a string to hold the random string
    std::string regNo;

    // Create a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Create a uniform distribution for the character set we want to use
    std::uniform_int_distribution<> dis(0, 35);

    // Generate a random string of length 10
    for (int i = 0; i < 7; i++)
    {
        // Generate a random number
        int randomNumber = dis(gen);

        // If the number is between 0 and 25, add an uppercase letter to the string
        if (randomNumber < 26)
        {
            char letter = 'A' + randomNumber;
            randomString += letter;
        }
            // If the number is between 26 and 35, add a digit to the string
        else
        {
            char digit = '0' + (randomNumber - 26);
            randomString += digit;
        }
    }

    return randomString;
}

// Checks if an input is an int or double
bool checkVariableType(const std::string& input) {

    // istringstream to read from input as a stream of data

    std::istringstream inputReader(input);
    double userInput;

    // Extract a double from the string stream
    inputReader >> userInput;

    // Check if the input can be converted to a double without any errors
    if (inputReader.fail() || inputReader.peek() != EOF) {
        return false;
    }
    return true;
}


