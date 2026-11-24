// TriageSystem.h
// This is the shared "list of promises" for the whole program.
// Every .cpp file includes this file so it can use the Patient struct,
// the shared patient list, the color numbers, and call the other functions.

// These three lines (#ifndef, #define, #endif) make sure the file is
// only read once by the compiler. You can ignore them.
#ifndef TRIAGESYSTEM_H
#define TRIAGESYSTEM_H

#include <string>
#include <vector>
using namespace std;

// A struct groups related data together.
// One Patient holds all the information about one person.
struct Patient {
    string id;           // Example: "P-0101"
    string name;         // Example: "Dela Cruz, Ana"
    int age;             // Age in years
    string bp;           // Blood pressure as text, like "160/95"
    int systolicBp;      // The top BP number (160 in "160/95")
    int hr;              // Heart rate in beats per minute
    double temp;         // Temperature in Celsius, like 38.5
    int deviationScore;  // How far the vitals are from normal (bigger = worse)
    string complaint;    // Main reason for the visit
    string triage;       // Category: "RED (1)", "YEL (2)", "AMB (3)" or "GRN (4)"
};

// These two variables are created in main.cpp.
// "extern" means: "they exist somewhere else, but let me use them here."
extern vector<Patient> patients;   // The list of all active patients
extern int nextPatientNumber;      // Used to give every patient a unique ID

// Color numbers used by the Windows console.
// We use these with the setColor() function.
const int TXT_WHITE  = 7;    // Normal text
const int TXT_RED    = 12;
const int TXT_YELLOW = 14;
const int TXT_AMBER  = 6;    // Dark yellow, looks orange
const int TXT_GREEN  = 10;
const int TXT_CYAN   = 11;

// ---------- Screen and color helpers ----------
void clearScreen();
void printHeader();
void pauseScreen();
void setColor(int colorNumber);
void setTriageColor(string triage);
void printError(string message);
void printTableLine();

// ---------- Input checking and converting ----------
bool isWholeNumber(string text);
bool isDecimalNumber(string text);
int textToInt(string text);
double textToDouble(string text);

// ---------- Input helpers (they keep asking until the input is valid) ----------
string readText(string prompt);
int readInt(string prompt, int minValue, int maxValue);
double readDouble(string prompt, int minValue, int maxValue);
string readBloodPressure(string prompt);
bool askYesNo(string prompt);

// ---------- Triage logic ----------
int extractSystolic(string bpText);
void evaluateAgeBasedTriage(int index);
void sortPatients();

// ---------- Patient list helpers ----------
int findPatient(string id);
string shorten(string text, int maxLength);

// ---------- Menu options ----------
void showQueue();
void registerPatient();
void viewPatient();
void updatePatient();
void dischargePatient();
void clinicStatistics();

#endif
