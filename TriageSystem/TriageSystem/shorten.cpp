// shorten.cpp
#include "TriageSystem.h"

// Cuts text that is too long so it fits inside a table column.
// Example: shorten("Severe chest pain", 6) returns "Severe".
string shorten(string text, int maxLength) {
    string result = "";
    int length = text.length();

    // Copy characters until we run out, or reach the maximum length.
    for (int i = 0; i < length && i < maxLength; i++) {
        result = result + text[i];
    }

    return result;
}
