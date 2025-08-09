#include "headers/dungeon.h"

using namespace std;

// Metodo per caricare linee di testo specifiche da un file JSON
string Textlines::generate_lines(string group) {
    ifstream inputFile("./lang/it.json"); // Apri il file JSON
    if (!inputFile.is_open()) {
        throw runtime_error("Could not open the file!"); // Usa runtime_error per le eccezioni
    }

    json j;
    inputFile >> j; // Analizza il file JSON

    // ritorna solo il gruppo specificato nel vettore appropriato
    Lines = j[group].get<vector<string>>();
    inputFile.close();
    return Lines[randRange(0, Lines.size() - 1)];
}