// extractSystolic.cpp
#include "TriageSystem.h"

// Gets the top (systolic) blood pressure number from text like "160/95".
// Example: "160/95" returns 160.
// If something is wrong with the text, it returns 120 (a normal value).
int extractSystolic(string bpText) {
    string topText = "";
    bool foundSlash = false;
    int length = bpText.length();

    // Copy the characters until we reach the "/".
    for (int i = 0; i < length && foundSlash == false; i++) {
        if (bpText[i] == '/') {
            foundSlash = true;
        } else {
            topText = topText + bpText[i];
        }
    }

    if (foundSlash == false || isWholeNumber(topText) == false) {
        return 120;
    }

    return textToInt(topText);
}
