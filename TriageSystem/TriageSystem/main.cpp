// main.cpp
// WVSU Clinic Intake - Acuity Triage System (CC 202 Final Project)
//
// This file holds the shared data and the main menu loop.
// The menu keeps repeating until the user chooses 0 (Exit).
// All data is kept in memory only, so it resets every time the program closes.

#include <iostream>
#include <iomanip>
#include "TriageSystem.h"

// The list of all active patients. Every file shares this one list.
vector<Patient> patients;

// The next ID number. It starts at 101 so the first ID is P-0101.
int nextPatientNumber = 101;

int main() {
    // Show decimals with 1 digit (so temperature prints as 38.5).
    cout << fixed << setprecision(1);

    int choice;

    // do-while: the menu shows at least once, then repeats until the user exits.
    do {
        clearScreen();
        printHeader();
        showQueue();

        setColor(TXT_CYAN);
        cout << "MAIN MENU\n";
        setColor(TXT_WHITE);
        cout << "[1] REGISTER PATIENT (Create)\n";
        cout << "[2] VIEW PATIENT DETAILS (Read)\n";
        cout << "[3] UPDATE VITALS & ACUITY (Update)\n";
        cout << "[4] DISCHARGE PATIENT (Delete)\n";
        cout << "[5] CLINIC STATISTICS\n";
        cout << "[0] EXIT\n\n";

        // readInt only accepts a number from 0 to 5, so no invalid choice gets through.
        choice = readInt("ENTER CHOSEN OPTION [0-5]: ", 0, 5);

        // Call the function that matches the user's choice.
        switch (choice) {
            case 1:
                registerPatient();
                break;
            case 2:
                viewPatient();
                break;
            case 3:
                updatePatient();
                break;
            case 4:
                dischargePatient();
                break;
            case 5:
                clinicStatistics();
                break;
            case 0:
                setColor(TXT_GREEN);
                cout << "\nExiting Triage System. Stay safe!\n";
                setColor(TXT_WHITE);
                break;
        }
    } while (choice != 0);

    return 0;
}
