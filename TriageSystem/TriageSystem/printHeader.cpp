// printHeader.cpp
#include <iostream>
#include "TriageSystem.h"

// Prints the school and project title at the top of every screen, in cyan.
void printHeader() {
    setColor(TXT_CYAN);

    // Print 98 "=" signs to make a line.
    for (int i = 0; i < 98; i++) {
        cout << "=";
    }
    cout << "\n";

    cout << "WEST VISAYAS STATE UNIVERSITY - CLINIC INTAKE\n";
    cout << "COLLEGE OF INFORMATION AND COMMUNICATIONS TECHNOLOGY (CICT)\n";
    cout << "CC 202 - FINAL PROJECT: ACUITY TRIAGE SYSTEM\n";

    for (int i = 0; i < 98; i++) {
        cout << "=";
    }
    cout << "\n\n";

    setColor(TXT_WHITE);   // Back to normal color
}
