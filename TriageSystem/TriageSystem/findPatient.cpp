// findPatient.cpp
#include "TriageSystem.h"

// Looks for a patient by ID (like "P-0101") in the patients list.
// Returns the position (index) of the patient in the list,
// or -1 if no patient has that ID.
int findPatient(string id) {
    // If the user typed a small "p", change it to a capital "P".
    if (id.length() > 0 && id[0] == 'p') {
        id[0] = 'P';
    }

    // Check every patient one by one.
    int total = patients.size();
    for (int i = 0; i < total; i++) {
        if (patients[i].id == id) {
            return i;   // Found! Send back the position.
        }
    }

    return -1;   // Not found
}
