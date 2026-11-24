// readDouble.cpp
#include <iostream>
#include "TriageSystem.h"

// Asks the user for a number that may have a decimal point (like a temperature)
// between minValue and maxValue. It keeps asking until the input is valid.
double readDouble(string prompt, int minValue, int maxValue) {
    string input;
    double value = 0;
    bool valid = false;

    do {
        cout << prompt;
        getline(cin, input);

        if (isDecimalNumber(input) == false) {
            printError("Invalid input. Please type a number like 38.5.");
        } else {
            value = textToDouble(input);

            if (value < minValue || value > maxValue) {
                printError("The value must be from " + to_string(minValue) + " to " + to_string(maxValue) + ".");
            } else {
                valid = true;
            }
        }
    } while (valid == false);

    return value;
}
