// isDecimalNumber.cpp
#include "TriageSystem.h"

// Checks if the text is a number that may have a decimal point, like "38.5".
// Returns true if it is valid, false if not.
// Example: "38.5" -> true, "38" -> true, "3.8.5" -> false, "abc" -> false
bool isDecimalNumber(string text) {
    int length = text.length();

    if (length == 0 || length > 8) {
        return false;
    }

    int dotCount = 0;     // How many "." we have seen
    int digitCount = 0;   // How many digits we have seen

    for (int i = 0; i < length; i++) {
        if (text[i] == '.') {
            dotCount++;
        } else if (text[i] >= '0' && text[i] <= '9') {
            digitCount++;
        } else {
            return false;   // Any other character is not allowed
        }
    }

    // Valid only if there is at most one dot and at least one digit.
    if (dotCount <= 1 && digitCount >= 1) {
        return true;
    }
    return false;
}
