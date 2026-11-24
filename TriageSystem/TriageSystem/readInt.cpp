// readInt.cpp
#include <iostream>
#include "TriageSystem.h"

// Asks the user for a whole number between minValue and maxValue.
// It keeps asking until the input is valid, so the program never crashes.
int readInt(string prompt, int minValue, int maxValue) {
    string input;
    int value = 0;
    bool valid = false;

    do {
        cout << prompt;
        getline(cin, input);

        if (isWholeNumber(input) == false) {
            printError("Invalid input. Please type a whole number.");
        } else {
            value = textToInt(input);

            if (value < minValue || value > maxValue) {
                printError("The number must be from " + to_string(minValue) + " to " + to_string(maxValue) + ".");
            } else {
                valid = true;
            }
        }
    } while (valid == false);

    return value;
}
