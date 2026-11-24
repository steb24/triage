// updatePatient.cpp
#include <iostream>
#include "TriageSystem.h"

// MENU OPTION 3: Update a patient's vitals. (UPDATE)
// The user types the patient ID. For each vital, the program asks
// "Change it? (y/n)". If yes, the user types the new value.
// After the update, the triage is calculated again.
void updatePatient() {
    clearScreen();
    printHeader();
    cout << "--- [3] UPDATE VITALS & ACUITY (Update) ---\n\n";

    if (patients.empty()) {
        printError("No patients available to update.");
        pauseScreen();
        return;
    }

    showQueue();

    string id;
    cout << "Enter Patient ID to update (e.g., P-0101): ";
    getline(cin, id);

    int index = findPatient(id);

    if (index == -1) {
        printError("Patient not found.");
        pauseScreen();
        return;
    }

    cout << "\nUpdating record for: " << patients[index].name
         << " (Age: " << patients[index].age << ")\n\n";

    // Blood pressure
    cout << "Current Blood Pressure: " << patients[index].bp << "\n";
    if (askYesNo("Change blood pressure? (y/n): ")) {
        patients[index].bp = readBloodPressure("New Blood Pressure (e.g., 120/80): ");
        patients[index].systolicBp = extractSystolic(patients[index].bp);
    }

    // Heart rate
    cout << "\nCurrent Heart Rate: " << patients[index].hr << "\n";
    if (askYesNo("Change heart rate? (y/n): ")) {
        patients[index].hr = readInt("New Heart Rate in bpm (20-250): ", 20, 250);
    }

    // Temperature
    cout << "\nCurrent Temperature: " << patients[index].temp << "\n";
    if (askYesNo("Change temperature? (y/n): ")) {
        patients[index].temp = readDouble("New Temperature in Celsius (30-45): ", 30, 45);
    }

    // Calculate the score and triage again using the new values.
    evaluateAgeBasedTriage(index);

    // Show the result. The message is green, and the triage uses its own color.
    setColor(TXT_GREEN);
    cout << "\n[+] Record updated! New Deviation Score: " << patients[index].deviationScore
         << " | New Triage: ";
    setTriageColor(patients[index].triage);
    cout << patients[index].triage << "\n";
    setColor(TXT_WHITE);

    // Put the list back in order, since the score may have changed.
    sortPatients();

    pauseScreen();
}
