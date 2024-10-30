// textlines.cpp
#include "headers/dungeon.h"
#include <cstdlib> // For rand()
#include <ctime>   // For time()

// Constructor
Textlines::Textlines() {
    load_lines(); // Automatically load lines when creating an instance
}

// Method to load text lines
void Textlines::load_lines() {
    enterLines = {
        "Entri nella stanza",
        "Preparati al combattimento!",
        "Attento agli angoli bui di questa sala"
    };

    victoryLines = {
        "Hai liberato questa stanza dal suo guardiano",
        "Emergi vittorioso dallo scontro",
        "Il tesoro è tuo!",
        "La vittoria è tua!"
    };
}

// Function to generate random text from a specified group
string Textlines::generate_text(const string& group) {
    vector<string> *selectedGroup;

    // Select the appropriate group based on the input parameter
    if (group == "enter")
        selectedGroup = &enterLines;
    else if (group == "victory")
        selectedGroup = &victoryLines;
    else
        throw "Invalid group specified!";

    // Generate a random index and return the corresponding string
    return (*selectedGroup)[randRange(0, selectedGroup -> size()-1)];
}