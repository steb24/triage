// viewPatient.cpp
#include <iostream>
#include "TriageSystem.h"

// MENU OPTION 2: View the full details of one patient. (READ)
// The queue table shortens long text, so this screen shows everything.
void viewPatient() {
    clearScreen();
    printHeader();
    cout << "--- [2] VIEW PATIENT DETAILS (Read) ---\n\n";

    if (patients.empty()) {
        printError("No patients in the queue.");
        pauseScreen();
        return;   // Leave the function early
    }

    showQueue();

    string id;
    cout << "Enter Patient ID to view (e.g., P-0101): ";
    getline(cin, id);

    int index = findPatient(id);

    if (index == -1) {
        printError("Patient not found.");
    } else {
        cout << "\n--- Patient Record ---\n";
        cout << "ID              : " << patients[index].id << "\n";
        cout << "Name            : " << patients[index].name << "\n";
        cout << "Age             : " << patients[index].age << "\n";
        cout << "Blood Pressure  : " << patients[index].bp << "\n";
        cout << "Heart Rate      : " << patients[index].hr << " bpm\n";
        cout << "Temperature     : " << patients[index].temp << " C\n";
        cout << "Chief Complaint : " << patients[index].complaint << "\n";
        cout << "Deviation Score : " << patients[index].deviationScore << "\n";
        cout << "Triage          : ";
        setTriageColor(patients[index].triage);
        cout << patients[index].triage << "\n";
        setColor(TXT_WHITE);
    }

    pauseScreen();
}
