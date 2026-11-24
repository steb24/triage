// setTriageColor.cpp
#include "TriageSystem.h"

// Sets the text color that matches a triage category.
// Call this BEFORE printing the triage text, then call setColor(TXT_WHITE) after.
void setTriageColor(string triage) {
    if (triage == "RED (1)") {
        setColor(TXT_RED);
    } else if (triage == "YEL (2)") {
        setColor(TXT_YELLOW);
    } else if (triage == "AMB (3)") {
        setColor(TXT_AMBER);
    } else {
        setColor(TXT_GREEN);
    }
}
