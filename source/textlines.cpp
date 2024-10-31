#include "headers/dungeon.h"
#include <cstdlib> // For rand()
#include <ctime>   // For time()
#include <fstream> // For file handling
#include <nlohmann/json.hpp> // Include the JSON library

using json = nlohmann::json; // Create an alias for convenience

// Constructor
Textlines::Textlines() {
    load_lines(); // Automatically load lines when creating an instance
}

// Method to load text lines from a JSON file
void Textlines::load_lines() {
    std::ifstream inputFile("lang/it.json"); // Open the JSON file
    if (!inputFile.is_open()) {
        throw "Could not open the file!";
    }

    json j;
    inputFile >> j; // Parse the JSON file

    // Load lines into vectors
    enterLines = j["enter"].get<std::vector<std::string>>();
    victoryLines = j["victory"].get<std::vector<std::string>>();

    inputFile.close(); // Close the file
}

// Function to generate random text from a specified group
string Textlines::generate_text(const string& group) {
    // Select the appropriate group based on the input parameter
    if (group == "enter")
        return enterLines[randRange(0,enterLines.size() - 1)];
    if (group == "victory")
        return victoryLines[randRange(0,victoryLines.size() - 1)];
    else
        throw "Invalid group specified!";
}