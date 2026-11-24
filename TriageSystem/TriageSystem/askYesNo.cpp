// askYesNo.cpp
#include <iostream>
#include "TriageSystem.h"

// Asks a yes/no question. The user must type y or n.
// Returns true for yes and false for no.
bool askYesNo(string prompt) {
    string input;
    bool answer = false;
    bool valid = false;

    do {
        cout << prompt;
        getline(cin, input);

        if (input == "y" || input == "Y") {
            answer = true;
            valid = true;
        } else if (input == "n" || input == "N") {
            answer = false;
            valid = true;
        } else {
            printError("Please type y or n.");
        }
    } while (valid == false);

    return answer;
}
