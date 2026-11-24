// textToInt.cpp
#include "TriageSystem.h"

// Changes text made of digits into a real number.
// Only use this after isWholeNumber() says the text is valid.
// Example: "42" becomes the number 42.
//
// How it works: we go through the digits from left to right.
//   Start with 0.
//   See '4': 0 * 10 + 4 = 4
//   See '2': 4 * 10 + 2 = 42
// (A digit character minus '0' gives its number value. Example: '7' - '0' = 7.)
int textToInt(string text) {
    int result = 0;
    int length = text.length();

    for (int i = 0; i < length; i++) {
        int digit = text[i] - '0';
        result = result * 10 + digit;
    }

    return result;
}
