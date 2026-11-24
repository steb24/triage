// evaluateAgeBasedTriage.cpp
#include "TriageSystem.h"

// This is the main triage logic. It gives a patient a deviation score
// and a triage category.
//
// "index" is the patient's position in the patients list.
// (The first patient is index 0, the second is index 1, and so on.)
// The function saves the score and category right into that patient.
//
// Idea: every age group has "normal" vitals. The further the patient's
// vitals are from normal, the higher the score, and the more urgent the case.
void evaluateAgeBasedTriage(int index) {
    // Copy the patient's values into short variable names to keep the code readable.
    int age = patients[index].age;
    int systolic = patients[index].systolicBp;
    int heartRate = patients[index].hr;
    double temperature = patients[index].temp;

    // Step 1: Find the age group. Age 24 / 10 = 2, which means the 20s.
    int ageGroup = age / 10;

    // Step 2: Pick the normal values for that age group.
    int normalSystolic;
    int normalHr;
    double normalTemp = 37.0;   // Normal temperature is the same for all ages

    switch (ageGroup) {
        case 0:  normalSystolic = 95;  normalHr = 100; break;   // 0-9 years
        case 1:  normalSystolic = 110; normalHr = 80;  break;   // 10-19 years
        case 2:  normalSystolic = 115; normalHr = 75;  break;   // 20-29 years
        case 3:  normalSystolic = 120; normalHr = 75;  break;   // 30-39 years
        case 4:  normalSystolic = 125; normalHr = 78;  break;   // 40-49 years
        case 5:  normalSystolic = 130; normalHr = 80;  break;   // 50-59 years
        default: normalSystolic = 135; normalHr = 82;  break;   // 60 years and up
    }

    // Step 3: Find how far each vital is from normal.
    // If the answer is negative, we make it positive (this is the "absolute value").
    int bpDeviation = systolic - normalSystolic;
    if (bpDeviation < 0) {
        bpDeviation = -bpDeviation;
    }

    int hrDeviation = heartRate - normalHr;
    if (hrDeviation < 0) {
        hrDeviation = -hrDeviation;
    }

    double tempDifference = temperature - normalTemp;
    if (tempDifference < 0) {
        tempDifference = -tempDifference;
    }
    // Multiply by 10 so even a small fever adds a noticeable amount to the score.
    // The + 0.5 rounds to the nearest whole number. (Computers store decimals
    // slightly off, so without it 37.3 could count as 2 points instead of 3.)
    int tempDeviation = (int)(tempDifference * 10 + 0.5);

    // Step 4: Add the three differences. This is the deviation score.
    int score = bpDeviation + hrDeviation + tempDeviation;
    patients[index].deviationScore = score;

    // Step 5: Choose the triage category based on the score.
    if (score >= 35) {
        patients[index].triage = "RED (1)";      // Needs attention immediately
    } else if (score >= 22) {
        patients[index].triage = "YEL (2)";      // Urgent
    } else if (score >= 12) {
        patients[index].triage = "AMB (3)";      // Can wait, but is monitored
    } else {
        patients[index].triage = "GRN (4)";      // Near normal, routine care
    }
}
