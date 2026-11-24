// sortPatients.cpp
#include "TriageSystem.h"

// Sorts the patients list so the HIGHEST deviation score comes first.
// That puts the most urgent patients at the top of the queue.
//
// This uses "bubble sort": compare two neighbors, and swap them if they
// are in the wrong order. Repeat until the whole list is in order.
void sortPatients() {
    int total = patients.size();

    for (int round = 0; round < total - 1; round++) {
        for (int i = 0; i < total - 1 - round; i++) {
            // If the left patient has a LOWER score than the right one, swap them.
            if (patients[i].deviationScore < patients[i + 1].deviationScore) {
                Patient temp = patients[i];
                patients[i] = patients[i + 1];
                patients[i + 1] = temp;
            }
        }
    }
}
