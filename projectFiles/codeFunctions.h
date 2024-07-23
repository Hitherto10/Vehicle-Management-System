#ifndef CW1_CODEFUNCTIONS_H
#define CW1_CODEFUNCTIONS_H

#include <string>
#include <vector>

/*
    Generate a random registration Number for the vehicles consisting of numbers and letters
    @return random generated string
 */
std::string generateRegNum();


/*
    Takes an input and attempts to convert it to a double without failure,
    if an error occurs then input is neither an integer nor double

    @param input - hold the string being verified by the function
    @return True if successful, False if unsuccessful
 */

bool checkVariableType(const std::string& input);


#endif
