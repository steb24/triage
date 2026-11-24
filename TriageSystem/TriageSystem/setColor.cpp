// setColor.cpp
// This is the ONLY file that uses <windows.h>.
// It changes the color of the text that is printed after it.
// (This works only on Windows.)

#include <windows.h>     // Gives us the Windows console functions
#include <iostream>
#include "TriageSystem.h"

// Changes the text color. Example: setColor(TXT_RED);
// Everything printed after this call will be in that color,
// until setColor is called again. Use TXT_WHITE to go back to normal.
void setColor(int colorNumber) {
    // Make sure any text still waiting to be printed comes out in the OLD color first.
    cout.flush();

    // Ask Windows for the console window, then set its text color.
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, colorNumber);
}
