// clinicStatistics.cpp
#include <iostream>
#include "TriageSystem.h"

// MENU OPTION 5: Show how many patients are in each triage category.
// This helps staff see quickly how busy and how critical the clinic is.
void clinicStatistics() {
    clearScreen();
    printHeader();
    cout << "--- [5] CLINIC STATISTICS ---\n\n";

    // Counters, all starting at zero.
    int red = 0;
    int yellow = 0;
    int amber = 0;
    int green = 0;

    // Go through every patient and add 1 to the matching counter.
    int total = patients.size();
    for (int i = 0; i < total; i++) {
        if (patients[i].triage == "RED (1)") {
            red++;
        } else if (patients[i].triage == "YEL (2)") {
            yellow++;
        } else if (patients[i].triage == "AMB (3)") {
            amber++;
        } else {
            green++;
        }
    }

    cout << "Total Active Patients in Queue : " << total << "\n";

    setColor(TXT_RED);
    cout << "Critical Cases (RED)           : " << red << "\n";
    setColor(TXT_YELLOW);
    cout << "Urgent Cases (YEL)             : " << yellow << "\n";
    setColor(TXT_AMBER);
    cout << "Delayed Cases (AMB)            : " << amber << "\n";
    setColor(TXT_GREEN);
    cout << "Routine Cases (GRN)            : " << green << "\n";
    setColor(TXT_WHITE);

    pauseScreen();
}
