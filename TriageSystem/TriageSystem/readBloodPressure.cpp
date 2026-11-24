// readBloodPressure.cpp
#include <iostream>
#include "TriageSystem.h"

// Asks the user for a blood pressure like "120/80" and keeps asking
// until the format and the numbers make sense.
// Rules: top number 50-250, bottom number 30-150, and the top must be bigger.
string readBloodPressure(string prompt) {
    string input;
    string result = "";
    bool valid = false;

    do {
        cout << prompt;
        getline(cin, input);

        // Split the typed text at the "/" into a top part and a bottom part.
        string topText = "";
        string bottomText = "";
        int slashCount = 0;
        int length = input.length();

        for (int i = 0; i < length; i++) {
            if (input[i] == '/') {
                slashCount++;
            } else if (slashCount == 0) {
                topText = topText + input[i];       // Before the "/"
            } else {
                bottomText = bottomText + input[i]; // After the "/"
            }
        }

        // Check the typed text step by step.
        if (slashCount != 1) {
            printError("Please use the format 120/80.");
        } else if (isWholeNumber(topText) == false || isWholeNumber(bottomText) == false) {
            printError("Please use numbers only, like 120/80.");
        } else {
            int top = textToInt(topText);
            int bottom = textToInt(bottomText);

            if (top < 50 || top > 250 || bottom < 30 || bottom > 150 || top <= bottom) {
                printError("Not a realistic reading. Top: 50-250, bottom: 30-150, top must be bigger.");
            } else {
                // Rebuild the text so it is always neat (example: "0120/080" becomes "120/80").
                result = to_string(top) + "/" + to_string(bottom);
                valid = true;
            }
        }
    } while (valid == false);

    return result;
}
