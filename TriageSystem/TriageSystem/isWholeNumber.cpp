// isWholeNumber.cpp
#include "TriageSystem.h"

// Checks if the text is a whole number like "25" (digits only).
// Returns true if it is valid, false if not.
// Example: "25" -> true, "2a" -> false, "" -> false, "-5" -> false
bool isWholeNumber(string text) {
    int length = text.length();

    // Empty text, or text that is too long, is not accepted.
    if (length == 0 || length > 6) {
        return false;
    }

    // Check every character. Digits are the characters from '0' to '9'.
    // If one character is outside that range, the text is invalid.
    for (int i = 0; i < length; i++) {
        if (text[i] < '0' || text[i] > '9') {
            return false;
        }
    }

    return true;
}
