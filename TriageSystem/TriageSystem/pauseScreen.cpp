// pauseScreen.cpp
#include <iostream>
#include "TriageSystem.h"

// Waits for the user to press Enter before going back to the menu.
void pauseScreen() {
    string dummy;
    cout << "\nPress Enter to return to the Main Menu...";
    getline(cin, dummy);
}
