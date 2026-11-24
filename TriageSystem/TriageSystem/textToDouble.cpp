// textToDouble.cpp
#include "TriageSystem.h"

// Changes text like "38.5" into a real decimal number.
// Only use this after isDecimalNumber() says the text is valid.
//
// How it works: digits before the "." work like textToInt.
// After the ".", each digit is worth less: the first is tenths,
// the next is hundredths, and so on.
//   "38.5": 3 -> 3, 8 -> 38, then "." , then 5 * 0.1 = 0.5, total 38.5
double textToDouble(string text) {
    double result = 0;
    double place = 1;         // The value of the current digit's place
    bool afterDot = false;    // Have we passed the "." yet?
    int length = text.length();

    for (int i = 0; i < length; i++) {
        if (text[i] == '.') {
            afterDot = true;
        } else {
            int digit = text[i] - '0';

            if (afterDot == false) {
                result = result * 10 + digit;
            } else {
                place = place / 10;            // 0.1, then 0.01, ...
                result = result + digit * place;
            }
        }
    }

    return result;
}
