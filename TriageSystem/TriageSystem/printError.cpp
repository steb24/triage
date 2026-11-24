// printError.cpp
#include <iostream>
#include "TriageSystem.h"

// Prints an error message in red, then goes back to normal color.
// Example: printError("Invalid input.") shows:  [!] Invalid input.
void printError(string message) {
    setColor(TXT_RED);
    cout << "[!] " << message << "\n";
    setColor(TXT_WHITE);
}
