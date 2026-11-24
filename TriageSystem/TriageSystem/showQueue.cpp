// showQueue.cpp
#include <iostream>
#include <iomanip>
#include "TriageSystem.h"

// Shows the queue table. The patients list is always kept sorted,
// so the most urgent patients appear first.
// This is the READ part of CRUD (it only shows data, it changes nothing).
//
// About <iomanip>: setw(6) means "use 6 characters of space for the next item".
// left / right choose if the text sits on the left or the right of that space.
// That is how the columns line up.
void showQueue() {
    cout << "ACTIVE PATIENT TRIAGE QUEUE (most urgent first)\n";

    // Table header
    printTableLine();
    cout << "| " << left << setw(6) << "ID"
         << " | " << setw(16) << "NAME"
         << " | " << setw(3) << "AGE"
         << " | " << setw(7) << "BP"
         << " | " << setw(3) << "HR"
         << " | " << setw(5) << "TEMP"
         << " | " << setw(18) << "COMPLAINT"
         << " | " << setw(5) << "SCORE"
         << " | " << setw(7) << "TRIAGE" << " |\n";
    printTableLine();

    int total = patients.size();

    if (total == 0) {
        cout << "| " << left << setw(94) << "[!] No active patients in queue." << " |\n";
    } else {
        // Print one row for each patient.
        for (int i = 0; i < total; i++) {
            cout << "| " << left << setw(6) << patients[i].id
                 << " | " << setw(16) << shorten(patients[i].name, 16)
                 << " | " << right << setw(3) << patients[i].age
                 << " | " << left << setw(7) << patients[i].bp
                 << " | " << right << setw(3) << patients[i].hr
                 << " | " << setw(5) << patients[i].temp
                 << " | " << left << setw(18) << shorten(patients[i].complaint, 18)
                 << " | " << right << setw(5) << patients[i].deviationScore
                 << " | ";

            // Print the triage text in its own color, then go back to white.
            setTriageColor(patients[i].triage);
            cout << left << setw(7) << patients[i].triage;
            setColor(TXT_WHITE);

            cout << " |\n";
        }
    }

    printTableLine();

    // The color guide under the table.
    setColor(TXT_RED);
    cout << "RED = HIGH DEVIATION";
    setColor(TXT_WHITE);
    cout << " | ";
    setColor(TXT_YELLOW);
    cout << "YEL = URGENT";
    setColor(TXT_WHITE);
    cout << " | ";
    setColor(TXT_AMBER);
    cout << "AMB = DELAYED";
    setColor(TXT_WHITE);
    cout << " | ";
    setColor(TXT_GREEN);
    cout << "GRN = NEAR NORMAL";
    setColor(TXT_WHITE);
    cout << "\n\n";
}
