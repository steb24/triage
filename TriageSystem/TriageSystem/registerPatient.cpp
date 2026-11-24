// registerPatient.cpp
#include <iostream>
#include "TriageSystem.h"

// MENU OPTION 1: Register a new patient. (CREATE)
// It asks for the patient's details, checks every answer,
// calculates the triage, and adds the patient to the list.
void registerPatient() {
    clearScreen();
    printHeader();
    cout << "--- [1] REGISTER PATIENT (Create) ---\n\n";

    Patient p;   // A new, empty patient record

    // The ID uses a counter that only goes UP, so IDs are never repeated,
    // even after patients are discharged. First patient: P-0101, then P-0102...
    p.id = "P-0" + to_string(nextPatientNumber);

    // Ask for each detail. These functions keep asking until the answer is valid.
    p.name = readText("Enter Patient Name (Last, First): ");
    p.age = readInt("Enter Age (0-120): ", 0, 120);
    p.bp = readBloodPressure("Enter Blood Pressure (e.g., 160/95): ");
    p.systolicBp = extractSystolic(p.bp);
    p.hr = readInt("Enter Heart Rate in bpm (20-250): ", 20, 250);
    p.temp = readDouble("Enter Temperature in Celsius (30-45, e.g., 38.5): ", 30, 45);
    p.complaint = readText("Enter Chief Complaint: ");

    // Add the patient to the end of the list, and move the ID counter up.
    patients.push_back(p);
    nextPatientNumber++;

    // The new patient is the last one in the list.
    // Their position (index) is the list size minus 1.
    int index = patients.size() - 1;

    // Calculate the deviation score and triage category.
    evaluateAgeBasedTriage(index);

    // Show the result. The message is green, and the triage uses its own color.
    setColor(TXT_GREEN);
    cout << "\n[+] Patient registered! ID: " << patients[index].id
         << " | Deviation Score: " << patients[index].deviationScore
         << " | Triage: ";
    setTriageColor(patients[index].triage);
    cout << patients[index].triage << "\n";
    setColor(TXT_WHITE);

    // Put the list back in order, with the most urgent patient first.
    sortPatients();

    pauseScreen();
}
