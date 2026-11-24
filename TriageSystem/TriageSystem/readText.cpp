// readText.cpp
#include <iostream>
#include "TriageSystem.h"

// Asks the user to type some text (like a name) and keeps asking
// until they type something that is not empty.
string readText(string prompt) {
    string input;
    bool valid = false;

    do {
        cout << prompt;
        getline(cin, input);

        // Look for at least one character that is not a space.
        int length = input.length();
        for (int i = 0; i < length; i++) {
            if (input[i] != ' ') {
                valid = true;
            }
        }

        if (valid == false) {
            printError("This cannot be empty. Please try again.");
        }
    } while (valid == false);

    return input;
}
