// dischargePatient.cpp
#include <iostream>
#include "TriageSystem.h"

// MENU OPTION 4: Discharge a patient. (DELETE)
// Finds the patient by ID and removes them from the list.
void dischargePatient() {
    clearScreen();
    printHeader();
    cout << "--- [4] DISCHARGE PATIENT (Delete) ---\n\n";

    if (patients.empty()) {
        printError("No patients in the queue to discharge.");
        pauseScreen();
        return;
    }

    showQueue();

    string id;
    cout << "Enter Patient ID to discharge (e.g., P-0101): ";
    getline(cin, id);

    int index = findPatient(id);

    if (index == -1) {
        printError("Patient ID not found.");
    } else {
        string dischargedId = patients[index].id;

        // Remove the patient by moving every patient after them one step forward.
        // Example: list is [A, B, C, D] and we remove B (index 1).
        //   B is replaced by C, then C is replaced by D -> [A, C, D, D]
        //   Then pop_back() removes the extra last item -> [A, C, D]
        int last = patients.size() - 1;
        for (int i = index; i < last; i++) {
            patients[i] = patients[i + 1];
        }
        patients.pop_back();

        setColor(TXT_GREEN);
        cout << "\n[+] Patient " << dischargedId << " has been discharged.\n";
        setColor(TXT_WHITE);
    }

    pauseScreen();
}
